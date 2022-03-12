#pragma once
#include "Button.h"
#include "Label.h"
#include "Text.h"
#include "Engine.h"

#include <vector>
#include <string>

class Button;
class Engine;

class Page
{
public:
	Page():curBtn_(0) {}
	Page(const std::vector<Text>& texts, const std::vector<Button>& btns, const std::vector<Label>& labels) : 
		texts_(texts), buttons_(btns), labels_(labels), curBtn_(0) {}
	void print()const;
	void printChObjects()const;
	
	void (*getAction())(Engine&);
	void cursorUp();
	void cursorDown();
	void addText(COORD coord, const std::string& text);
	void setText(int num, std::string text);
	void addLabel(COORD coord, const int* value);
	size_t getTextsSize()const;
private:
	std::vector<Text> texts_;
	std::vector<Label> labels_;
	std::vector<Button> buttons_;
	size_t curBtn_;

	void updateCursor()const;
};

