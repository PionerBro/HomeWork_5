#include "Cow.h"
#include <iostream>

Cow::Cow(const std::string& name, int hungerLevel) : Animal(name, hungerLevel, Food::Hay)
{
}

std::string Cow::Happy() const
{
	return "Myyy!!!";
}

