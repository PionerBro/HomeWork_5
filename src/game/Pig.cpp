#include "Pig.h"
#include <iostream>

Pig::Pig(const std::string& name, int hungerLevel):Animal(name, hungerLevel, Food::Vegetables)
{
}

std::string Pig::Happy() const
{
	return "Hru-hru!!!";
}
