#include "Text.h"
#include <iostream>


void Text::print() const
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord_);
	std::cout << text_;
}
