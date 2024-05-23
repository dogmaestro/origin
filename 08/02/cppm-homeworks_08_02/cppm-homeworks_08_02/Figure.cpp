#include <iostream>
#include "Figure.h"

Figure::Figure() {
	name = "Фигура";
	sides_count = 0;
};

std::string Figure::get_name() { return name; }

std::string Figure::getCreationInfo() { 
	return  "Фигура создана "; 
}
