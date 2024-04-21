#include <iostream>

struct Account {
	std::string accountNo;
	std::string name;
	double balance;
};

void changeBalance(Account& account, double newBalance) {
	account.balance = newBalance;
}

int main() {
	Account account;
	double newBalance;
	std::cout << "Введите номер счета: ";
	std::cin >> account.accountNo;
	std::cout << "Введите имя владельца: ";
    std::cin >> account.name;
	std::cout << "Введите баланс: ";
    std::cin >> account.balance;
	std::cout << "Введите новый баланс: ";
    std::cin >> newBalance;
	changeBalance(account, newBalance);
	std::cout << "Ваш счет: " << account.name << ", " << account.accountNo << ", " << account.balance << std::endl;
	return 0;
};
