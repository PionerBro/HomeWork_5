#pragma once
#include <Windows.h>
#include <string>
#include <iostream>

class Label
{
public:
	Label() : value_(nullptr), coord_({ 0,0 }) {}
	Label(const int* value, COORD coord) :value_(value), coord_(coord) {}


	void print() const;

	const int* value_;
	COORD coord_;
};

