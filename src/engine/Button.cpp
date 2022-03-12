#include "Button.h"
#include <iostream>


void Button::print() const
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord_);
	std::cout << text_;
}
