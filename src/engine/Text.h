#pragma once
#include <string>
#include <Windows.h>

class Text
{
public:
	Text() : coord_({0,0}) {}
	Text(const std::string& text, COORD coord) :text_(text), coord_(coord) {}

	void print()const;

	std::string text_;
	COORD coord_;
};

