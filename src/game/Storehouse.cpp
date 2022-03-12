#include "Storehouse.h"
#include <iostream>

Storehouse::Storehouse():number_(cg_foodNames.size())
{
}

void Storehouse::addFood(Food food, int number)
{
	number_[static_cast<size_t>(food)] += number;
}

int Storehouse::getNumber(Food food) const
{
	return number_[static_cast<size_t>(food)];
}

void Storehouse::print() const
{
	for (int i = 0; i < cg_foodNames.size(); ++i)
		std::cout << cg_foodNames[i] << ":" << getNumber(static_cast<Food>(i)) << " ";
	std::cout << "\n";
}

int& Storehouse::getFoodRef(Food num)
{
	return number_[static_cast<size_t>(num)];
}
