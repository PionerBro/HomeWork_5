#pragma once

#include "Food.h"
#include <vector>

class Storehouse
{
	friend class Engine;
public:
	Storehouse();
	void addFood(Food food, int number);
	int getNumber(Food food) const;
	void print()const;
private:
	int& getFoodRef(Food num);
	std::vector<int> number_;
};

