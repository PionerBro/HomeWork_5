#pragma once
#include "Animal.h"

class Cow : public Animal
{
public:
	Cow(const std::string& name, int hungerLimit);
	std::string Happy()const override;
};

