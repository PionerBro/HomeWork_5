#include "Page.h"
#include <Windows.h>


void Page::print() const
{
	for (const auto& text : texts_)
		text.print();
	for (const auto& label : labels_)
		label.print();
	for (const auto& button : buttons_)
		button.print();
	updateCursor();
}

void Page::printChObjects() const
{
	for (const auto& label : labels_)
		label.print();
	updateCursor();
}

void(*Page::getAction())(Engine&)
{
	return buttons_[curBtn_].action_;
}

void Page::cursorUp()
{
	if (curBtn_) {
		--curBtn_;
		updateCursor();
	}
}

void Page::cursorDown()
{
	if (curBtn_ < buttons_.size() - 1) {
		++curBtn_;
		updateCursor();
	}
}

void Page::addText(COORD coord, const std::string& text)
{
	texts_.push_back({text, coord});
}

void Page::setText(int num, std::string text)
{
	texts_[num].text_ = text;
}

void Page::addLabel(COORD coord, const int* value)
{
	labels_.push_back({ value, coord });
}

size_t Page::getTextsSize() const
{
	return texts_.size();
}

void Page::updateCursor() const
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), buttons_[curBtn_].coord_);
}
