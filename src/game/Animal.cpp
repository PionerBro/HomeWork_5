#include "Animal.h"
#include <iostream>
#include <algorithm>

Animal::Animal(const std::string& name, int hungerLimit, Food foodType) : name_(name), hungerLevel_(hungerLimit), hungerLimit_(hungerLimit), foodType_(foodType)
{
}

Animal::~Animal()
{
}

std::string Animal::Eat(int& foodCount)
{
	int eatenFood = foodCount - hungerLevel_;
	if (eatenFood < 0) {
		hungerLevel_ = hungerLevel_ - foodCount;
		return Angry();
	}
	else
	{
		foodCount = hungerLevel_;
		hungerLevel_ = 0;
		return Happy();
	}
}

std::string Animal::Angry() const
{
	return "BRrr!!! Hunger: " + std::to_string(hungerLevel_);
}

std::string Animal::Happy() const
{
	return "I'm happy";
}

Food Animal::getFoodType() const
{
	return foodType_;
}

void Animal::incHungerLevel()
{
	if (hungerLevel_ < hungerLimit_)
		++hungerLevel_;
}
