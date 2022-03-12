#pragma once
#include <vector>
#include <string>
#include "Food.h"

class Animal
{
	friend class Engine;
public:
	Animal(const std::string& name, int hungerLimit, Food foodType_);
	virtual ~Animal();
	std::string Eat(int& foodCount);
	virtual std::string Angry() const;
	virtual std::string Happy() const = 0;
	Food getFoodType()const;
	void incHungerLevel();
private:
	std::string name_;
	int hungerLevel_;
	int hungerLimit_;
	Food foodType_;
};
