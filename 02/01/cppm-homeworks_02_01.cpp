#include <iostream>

enum class Months {
  JANUARY = 1,
  FEBRUARY,
  MARCH,
  APRIL,
  MAY,
  JUNE,
  JULY,
  AUGUST,
  SEPTEMBER,
  OCTOBER,
  NOVEMBER,
  DECEMBER
};

int main(int argc, char** argv)
{
	int number;
	std::cout << "Введите номер месяца: ";
	std::cin >> number;
	while(number != 0) {
      switch (static_cast<Months>(number)) {
		  case Months::JANUARY:
			  std::cout << "Январь" << std::endl;
			  break;
		  case Months::FEBRUARY:
			  std::cout << "Февраль" << std::endl;
			  break;
    	  case Months::MARCH:
			  std::cout << "Март" << std::endl;
			  break;
    	  case Months::APRIL:
			  std::cout << "Апрель" << std::endl;
			  break;
    	  case Months::MAY:
			  std::cout << "Май" << std::endl;
			  break;
		  case Months::JUNE:
			  std::cout << "Июнь" << std::endl;
			  break;
		  case Months::JULY:
			  std::cout << "Июль" << std::endl;
			  break;
		  case Months::AUGUST:
			  std::cout << "Август" << std::endl;
			  break;
		  case Months::SEPTEMBER:
			  std::cout << "Сентябрь" << std::endl;
			  break;
		  case Months::OCTOBER:
			  std::cout << "Октябрь" << std::endl;
			  break;
		  case Months::NOVEMBER:
			  std::cout << "Ноябрь" << std::endl;
			  break;
		  case Months::DECEMBER:
			  std::cout << "Декабрь" << std::endl;
			  break;
	  }
	  std::cout << "Введите номер месяца: ";
	  std::cin >> number;
	};



}
