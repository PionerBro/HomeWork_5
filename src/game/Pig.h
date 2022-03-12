#pragma once
#include "Animal.h"

class Pig : public Animal
{
public:
	Pig(const std::string& name, int hungerLimit);
	std::string Happy()const override;
};

