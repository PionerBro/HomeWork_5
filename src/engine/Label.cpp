#include "Label.h"
#include <iostream>

void Label::print() const
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord_);
	std::cout << *value_;
}
