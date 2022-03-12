#include "Farm.h"
#include "Animal.h"

#include <algorithm>
#include <iostream>

Farm::Farm()
{
}

Farm::~Farm()
{
	for (int i = 0; i < animals_.size(); ++i)
		delete animals_[i];
}

std::vector<std::string> Farm::Feed()
{
	std::vector<std::string> texts;
	texts.reserve(animals_.size());
	for (auto animal : animals_)
	{
		Food food = animal->getFoodType();
		int number = storehouse_.getNumber(food);
		texts.push_back(animal->Eat(number));
		storehouse_.addFood(food, -number);
	}
	return texts;
}

void Farm::addFoodNumber(Food food, int number)
{
	storehouse_.addFood(food, number);
}

void Farm::addAnimal(Animal* animal)
{
	animals_.push_back(&(*animal));
}

void Farm::printStoreHouse() const
{
	storehouse_.print();
}

void Farm::tic()
{
	for (auto animal : animals_)
		animal->incHungerLevel();
}


