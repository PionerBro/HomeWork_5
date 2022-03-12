#include "Chicken.h"
#include <iostream>

Chicken::Chicken(const std::string& name, int hungerLevel):Animal(name, hungerLevel, Food::Grain)
{
}

std::string Chicken::Happy() const
{
	return "Ko-ko-ko!!!";
}
