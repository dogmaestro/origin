#include <iostream>
#include <pqxx/pqxx>
#include <string>
// #include <Windows.h>
#include <vector>
#include <optional>

struct ClientData
{
	int id;
	std::string name;
	std::string last_name;
	std::string email;
};

class ClientDBManager
{
public:
	ClientDBManager();
	void initConnection(const std::string &connection_str);
	void createDatabaseStructure();
	int addClient(const std::string &name, const std::string &last_name, const std::string &email, const std::vector<std::string> &phone_numbers);
	void addPhoneToClient(std::string &phone_number, const int &client_id);
	void updateClient(const std::string &name, const std::string &last_name, const std::string &email, const std::vector<std::string> &phone_numbers, const int &client_id);
	void deletePhoneToClient(std::string &phone_number, const int &client_id);
	void deleteClient(const int &client_id);
	std::optional<ClientData> findClient(const std::string &name, const std::string &last_name, const std::string &email, const std::string &phone_number);

private:
	std::unique_ptr<pqxx::connection> conn;
};

ClientDBManager::ClientDBManager() {};

void ClientDBManager::initConnection(const std::string &connection_str)
{
	conn = std::make_unique<pqxx::connection>(connection_str);
	if (!conn->is_open())
	{
		throw "Ошибка соединения с БД";
	}
};

void ClientDBManager::createDatabaseStructure()
{
	pqxx::transaction t(*conn);

	t.exec(
		"CREATE TABLE IF NOT EXISTS clients ( "
		"id SERIAL PRIMARY KEY, "
		"name VARCHAR(100) NOT NULL, "
		"last_name VARCHAR(100) NOT NULL, "
		"email VARCHAR(100) NOT NULL UNIQUE);");

	t.exec(
		"CREATE TABLE IF NOT EXISTS phones ("
		"id SERIAL PRIMARY KEY, "
		"client_id INTEGER NOT NULL, "
		"phone_number VARCHAR(100) NOT NULL, "
		"FOREIGN KEY (client_id) REFERENCES clients(id) ON DELETE CASCADE);");

	t.commit();
};

int ClientDBManager::addClient(const std::string &name, const std::string &last_name, const std::string &email, const std::vector<std::string> &phone_numbers)
{
	pqxx::transaction t(*conn);

	pqxx::result result = t.exec("INSERT INTO clients (name, last_name, email) VALUES (" +
								 t.quote(name) + ", " +
								 t.quote(last_name) + ", " +
								 t.quote(email) +
								 ") RETURNING id;");
	int client_id = result[0][0].as<int>();

	for (const auto &phone : phone_numbers)
	{
		t.exec("INSERT INTO phones (client_id, phone_number) VALUES (" +
			   t.quote(client_id) + ", " + t.quote(phone) + ");");
	}

	t.commit();
	return client_id;
}

void ClientDBManager::updateClient(const std::string &new_name, const std::string &new_last_name, const std::string &new_email, const std::vector<std::string> &new_phone_numbers, const int &client_id)
{
	pqxx::transaction t(*conn);

	pqxx::result result = t.exec("UPDATE clients SET name = " + t.quote(new_name) +
								 ", last_name = " + t.quote(new_last_name) +
								 ", email = " + t.quote(new_email) +
								 " WHERE id = " + t.quote(client_id));

	t.exec("DELETE FROM phones WHERE id = " + t.quote(client_id));

	for (const auto &phone : new_phone_numbers)
	{
		t.exec("INSERT INTO phones (client_id, phone_number) VALUES (" +
			   t.quote(client_id) + ", " + t.quote(phone) + ");");
	}

	t.commit();
}

void ClientDBManager::addPhoneToClient(std::string &phone_number, const int &client_id)
{
	pqxx::transaction t(*conn);

	t.exec("INSERT INTO phones (client_id, phone_number) VALUES (" +
		   t.quote(client_id) + ", " + t.quote(phone_number) + ");");
	t.commit();
}

void ClientDBManager::deletePhoneToClient(std::string &phone_number, const int &client_id)
{
	pqxx::transaction t(*conn);

	t.exec("DELETE FROM phones WHERE client_id = " + t.quote(client_id) + " AND phone_number = " + t.quote(phone_number) + ";");
	t.commit();
}

void ClientDBManager::deleteClient(const int &client_id)
{
	try
	{
		pqxx::transaction t(*conn);

		t.exec("DELETE FROM clients WHERE id = " + t.quote(client_id) + ";");
		t.commit();
	}

	catch (const std::exception &e)
	{
		std::cerr << "Ошибка удаления клиента: " << e.what() << std::endl;
		exit(1);
	}
}

std::optional<ClientData> ClientDBManager::findClient(const std::string &name, const std::string &last_name, const std::string &email, const std::string &phone_number)
{
	std::string sql;
	pqxx::transaction t(*conn);

	if (phone_number.empty())
	{
		sql = "SELECT * FROM clients c WHERE ";
	}
	else
	{
		sql = "SELECT * FROM clients c JOIN phones p ON c.id = p.client_id WHERE ";
	}

	bool useAND = false;

	if (!name.empty())
	{
		sql += "c.name = " + t.quote(name);
		useAND = true;
	}

	if (!last_name.empty())
	{
		if (useAND)
			sql += " AND ";
		sql += "c.last_name = " + t.quote(last_name);
		useAND = true;
	}

	if (!email.empty())
	{
		if (useAND)
			sql += " AND ";
		sql += "c.email = " + t.quote(email);
		useAND = true;
	}

	if (!phone_number.empty())
	{
		if (useAND)
			sql += " AND ";
		sql += "p.phone_number = " + t.quote(phone_number);
	}

	pqxx::result res = t.exec(sql);

	if (res.empty())
	{
		return std::nullopt;
	}
	else
	{
		ClientData clientData;
		clientData.id = res[0]["id"].as<int>();						  
		clientData.name = res[0]["name"].as<std::string>();			  
		clientData.last_name = res[0]["last_name"].as<std::string>(); 
		clientData.email = res[0]["email"].as<std::string>();		  

		return clientData;
	}
}

void printClient(std::optional<ClientData> clientData)
{
	if (clientData)
	{
		const auto &client = *clientData;
		std::cout << "Клиент: "
				  << "имя = " << client.name << ", "
				  << "фамилия = " << client.last_name << ", "
				  << "Email = " << client.email << std::endl;
	}
	else
	{
		std::cout << "Клиент не найден" << std::endl;
	}
}

int main()
{
	// system("chcp 1251");
	// setlocale(LC_ALL, "ru_RU.UTF-8");

	std::string connection_str = "dbname=postgres user=postgres password=password hostaddr=127.0.0.1 port=5432";
	std::string name;
	std::string last_name;
	std::string email;
	std::string phone_number;
	std::vector<std::string> phone_numbers;
	ClientDBManager manager;
	int client_id1;
	int client_id2;

	try
	{
		manager.initConnection(connection_str);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Ошибка соединения: " << e.what() << std::endl;
		return -1;
	};

	try
	{
		manager.createDatabaseStructure();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Ошибка создания таблиц: " << e.what() << std::endl;
		return -2;
	};

	try
	{
		name = "Иван";
		last_name = "Иванов";
		email = "ivanov@mail.com";
		phone_numbers = {"123-456-789", "111-222-333"};
		client_id1 = manager.addClient(name, last_name, email, phone_numbers);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Ошибка добавления клиента: " << e.what() << std::endl;
	}

	try
	{
		phone_number = "333-444-555";
		manager.addPhoneToClient(phone_number, client_id1);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Ошибка добавления телефона: " << e.what() << std::endl;
	}

	try
	{
		name = "Иван2";
		last_name = "Иванов2";
		email = "ivanov2@mail.com";
		phone_numbers = {"777-765-098", "567-432-742"};
		client_id2 = manager.addClient(name, last_name, email, phone_numbers);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Ошибка добавления клиента: " << e.what() << std::endl;
	}

	try
	{
		phone_number = "333-444-555";
		manager.addPhoneToClient(phone_number, client_id2);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Ошибка добавления телефона: " << e.what() << std::endl;
	}

	try
	{
		name = "Петр";
		last_name = "Петров";
		email = "petrov@mail.com";
		phone_numbers = {"444-555-666", "777-888-999"};
		manager.updateClient(name, last_name, email, phone_numbers, client_id1);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Ошибка изменения клиента: " << e.what() << std::endl;
	}

	try
	{
		phone_number = "777-888-999";
		manager.deletePhoneToClient(phone_number, client_id1);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Ошибка удаления телефона: " << e.what() << std::endl;
	}

	try
	{
		manager.deleteClient(client_id2);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Ошибка удаления клиента: " << e.what() << std::endl;
	}

	try
	{
		name = "Иван";
		last_name = "Иванов";
		email = "ivanov@mail.com";
		printClient(manager.findClient(name, last_name, email, ""));
	}
	catch (const std::exception &e)
	{
		std::cerr << "Ошибка поиска клиента: " << e.what() << std::endl;
	}

	try
	{
		name = "Петр";
		last_name = "Петров";
		email = "petrov@mail.com";
		phone_number = "444-555-666";
		printClient(manager.findClient(name, last_name, email, phone_number));
	}
	catch (const std::exception &e)
	{
		std::cerr << "Ошибка поиска клиента: " << e.what() << std::endl;
	}

	return 0;
}
