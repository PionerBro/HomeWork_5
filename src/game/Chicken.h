#pragma once
#include "Animal.h"

class Chicken : public Animal
{
public:
	Chicken(const std::string& name, int hungerLimit);
	std::string Happy()const override;
};

