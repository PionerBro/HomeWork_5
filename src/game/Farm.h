#pragma once

#include "Storehouse.h"
#include "Pig.h"
#include "Cow.h"
#include "Chicken.h"

#include <vector>

class Animal;

class Farm
{
	friend class Engine;
public:
	Farm();
	~Farm();

	std::vector<std::string> Feed();
	void addFoodNumber(Food index, int number);
	void addAnimal(Animal* animal);
	void printStoreHouse()const;
	void tic();
private:
	Storehouse storehouse_;
	std::vector<Animal*> animals_;
};

