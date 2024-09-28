#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/Session.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <iostream>
#include <tuple>
#include <optional>
#include <set>

class Book;
class Stock;
class Sale;

class Publisher
{
public:
    std::string name;

    template <class Action>
    void persist(Action &a)
    {
        Wt::Dbo::field(a, name, "name");
    }
    Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books;
};

class Shop
{
public:
    std::string name;

    template <class Action>
    void persist(Action &a)
    {
        Wt::Dbo::field(a, name, "name");
    }
    Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;
};

class Book
{
public:
    std::string title;
    Wt::Dbo::ptr<Publisher> publisher;

    template <class Action>
    void persist(Action &a)
    {
        Wt::Dbo::field(a, title, "title");
        Wt::Dbo::belongsTo(a, publisher, ">id_publisher");
    }
    Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;
};

class Stock
{
public:
    Wt::Dbo::ptr<Book> book;
    Wt::Dbo::ptr<Shop> shop;
    int count;

    template <class Action>
    void persist(Action &a)
    {
        Wt::Dbo::belongsTo(a, book, ">id_book"); 
        Wt::Dbo::belongsTo(a, shop, ">id_shop"); 
        Wt::Dbo::field(a, count, "count");
    }
    Wt::Dbo::collection<Wt::Dbo::ptr<Sale>> sales;
};

class Sale
{
public:
    int price;
    std::string date_sale;
    Wt::Dbo::ptr<Stock> stock;
    int count;

    template <class Action>
    void persist(Action &a)
    {
        Wt::Dbo::field(a, price, "price");
        Wt::Dbo::field(a, date_sale, "date_sale");
        Wt::Dbo::belongsTo(a, stock, ">id_stock");
        Wt::Dbo::field(a, count, "count");
    }
};

void fillTables(Wt::Dbo::Session &session)
{
    Wt::Dbo::Transaction t(session);
    Wt::Dbo::ptr<Publisher> publisher1 = session.add(std::unique_ptr<Publisher>{new Publisher{"Publisher 1"}});
    Wt::Dbo::ptr<Publisher> publisher2 = session.add(std::unique_ptr<Publisher>{new Publisher{"Publisher 2"}});
    Wt::Dbo::ptr<Publisher> publisher3 = session.add(std::unique_ptr<Publisher>{new Publisher{"Publisher 3"}});

    Wt::Dbo::ptr<Book> book1 = session.add(std::unique_ptr<Book>{new Book{"Book 1", publisher1}});
    Wt::Dbo::ptr<Book> book2 = session.add(std::unique_ptr<Book>{new Book{"Book 2", publisher1}});
    Wt::Dbo::ptr<Book> book3 = session.add(std::unique_ptr<Book>{new Book{"Book 3", publisher2}});
    Wt::Dbo::ptr<Book> book4 = session.add(std::unique_ptr<Book>{new Book{"Book 4", publisher2}});
    Wt::Dbo::ptr<Book> book5 = session.add(std::unique_ptr<Book>{new Book{"Book 5", publisher3}});
    Wt::Dbo::ptr<Book> book6 = session.add(std::unique_ptr<Book>{new Book{"Book 6", publisher3}});

    Wt::Dbo::ptr<Shop> shop1 = session.add(std::unique_ptr<Shop>{new Shop{"Shop 1"}});
    Wt::Dbo::ptr<Shop> shop2 = session.add(std::unique_ptr<Shop>{new Shop{"Shop 2"}});
    Wt::Dbo::ptr<Shop> shop3 = session.add(std::unique_ptr<Shop>{new Shop{"Shop 3"}});

    Wt::Dbo::ptr<Stock> stock1 = session.add(std::unique_ptr<Stock>{new Stock{book1, shop1, 10}});
    Wt::Dbo::ptr<Stock> stock2 = session.add(std::unique_ptr<Stock>{new Stock{book2, shop2, 120}});
    Wt::Dbo::ptr<Stock> stock3 = session.add(std::unique_ptr<Stock>{new Stock{book3, shop3, 2}});
    Wt::Dbo::ptr<Stock> stock4 = session.add(std::unique_ptr<Stock>{new Stock{book4, shop1, 52}});
    Wt::Dbo::ptr<Stock> stock5 = session.add(std::unique_ptr<Stock>{new Stock{book5, shop2, 78}});
    Wt::Dbo::ptr<Stock> stock6 = session.add(std::unique_ptr<Stock>{new Stock{book6, shop3, 92}});
    Wt::Dbo::ptr<Stock> stock7 = session.add(std::unique_ptr<Stock>{new Stock{book1, shop1, 111}});
    Wt::Dbo::ptr<Stock> stock8 = session.add(std::unique_ptr<Stock>{new Stock{book2, shop2, 4}});
    Wt::Dbo::ptr<Stock> stock9 = session.add(std::unique_ptr<Stock>{new Stock{book3, shop3, 7}});
    Wt::Dbo::ptr<Stock> stock10 = session.add(std::unique_ptr<Stock>{new Stock{book4, shop1, 80}});
    Wt::Dbo::ptr<Stock> stock11 = session.add(std::unique_ptr<Stock>{new Stock{book5, shop2, 36}});
    Wt::Dbo::ptr<Stock> stock12 = session.add(std::unique_ptr<Stock>{new Stock{book6, shop3, 18}});

    session.add(std::unique_ptr<Sale>{new Sale{123, "15-01-2017", stock1, 7}});
    session.add(std::unique_ptr<Sale>{new Sale{456, "15-01-2017", stock2, 4}});
    session.add(std::unique_ptr<Sale>{new Sale{789, "16-01-2017", stock3, 8}});
    session.add(std::unique_ptr<Sale>{new Sale{435, "16-01-2017", stock4, 1}});
    session.add(std::unique_ptr<Sale>{new Sale{852, "17-01-2017", stock5, 3}});
    session.add(std::unique_ptr<Sale>{new Sale{156, "17-01-2017", stock6, 9}});
    session.add(std::unique_ptr<Sale>{new Sale{148, "18-01-2017", stock7, 0}});
    session.add(std::unique_ptr<Sale>{new Sale{238, "18-01-2017", stock8, 2}});
    session.add(std::unique_ptr<Sale>{new Sale{175, "19-01-2017", stock9, 11}});
    session.add(std::unique_ptr<Sale>{new Sale{845, "19-01-2017", stock10, 5}});
    session.add(std::unique_ptr<Sale>{new Sale{526, "20-01-2017", stock11, 6}});
    session.add(std::unique_ptr<Sale>{new Sale{145, "20-01-2017", stock12, 3}});
    session.add(std::unique_ptr<Sale>{new Sale{745, "21-01-2017", stock1, 2}});
    session.add(std::unique_ptr<Sale>{new Sale{175, "21-01-2017", stock2, 1}});
    session.add(std::unique_ptr<Sale>{new Sale{542, "22-01-2017", stock3, 4}});
    session.add(std::unique_ptr<Sale>{new Sale{248, "22-01-2017", stock4, 7}});

    t.commit();
}

bool containsDigits(const std::string &input)
{
    return std::any_of(input.begin(), input.end(), ::isdigit);
}

std::optional<std::tuple<std::string, std::set<std::string>>> getInfo(Wt::Dbo::Session &session, const std::string &puplisher_input)
{
    Wt::Dbo::Transaction t(session);
    std::string condition;
    typedef Wt::Dbo::ptr<Publisher> PublisherPtr;
    typedef Wt::Dbo::collection<PublisherPtr> Publishers;
    typedef Wt::Dbo::ptr<Book> BookPtr;
    typedef Wt::Dbo::collection<BookPtr> Books;
    typedef Wt::Dbo::ptr<Stock> StockPtr;
    typedef Wt::Dbo::collection<StockPtr> Stocks;

    if (containsDigits(puplisher_input))
    {
        condition = "id = ?";
    }
    else
    {
        condition = "name = ?";
    }

    auto queryPublishers = session.find<Publisher>().where(condition).bind(puplisher_input);
    Publishers publishers = queryPublishers.resultList();

    if (publishers.size() == 0)
    {
        return std::nullopt;
    }

    auto publisher = publishers.front();

    std::set<std::string> result;

    auto queryBooks = session.find<Book>().where("id_publisher = ?").bind(publisher.id());
    Books books = queryBooks.resultList();

    for (const auto &book : books)
    {
        auto queryStocks = session.find<Stock>().where("id_book = ?").bind(book.id());
        Stocks stocks = queryStocks.resultList();

        for (const auto &stock : stocks)
        {
            result.insert(stock->shop->name);
        }
    }
    return std::make_tuple(publisher->name, result);
}

int main()
{
    try
    {
        std::string connectionString = "dbname=postgres user=postgres password=password hostaddr=127.0.0.1 port=5432";
        auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);
        Wt::Dbo::Session session;
        session.setConnection(std::move(postgres));

        session.mapClass<Publisher>("publisher");
        session.mapClass<Shop>("shop");
        session.mapClass<Book>("book");
        session.mapClass<Stock>("stock");
        session.mapClass<Sale>("sale");

        session.createTables();

        fillTables(session);

        std::string id_publisher;
        std::cout << "Введите идентификатор издателя: ";
        std::cin >> id_publisher;
        std::cout << std::endl;
        auto result = getInfo(session, id_publisher);
        if (result)
        {
            const auto &info = *result;
            std::cout << "Издатель: " << std::get<0>(info) << std::endl;

            for (const auto &shopName : std::get<1>(info))
            {
                std::cout << " Присутствует в: " << shopName << std::endl;
            }
        }
        else
        {
            std::cout << "Издатель не найден." << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
