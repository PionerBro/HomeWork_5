#pragma once
#include <string>
#include <Windows.h>
#include "Engine.h"

class Engine;

class Button
{
public:
	Button() : coord_({ 0,0 }), action_(nullptr) {}
	Button(COORD coord, const std::string& text, void (*action)(Engine&)) :coord_(coord), text_(text), action_(action) {}
	//Button(const Button&) = delete;
	//Button& operator=(const Button&) = delete;


	void print() const;


	COORD coord_;
	std::string text_;
	void (*action_)(Engine&);
};

