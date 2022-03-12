#pragma once
#include <vector>
#include <string>
#include <list>

#include "src/game/Farm.h"
#include "Button.h"
#include "Page.h"

class Engine;
class Page;
class Button;
class Text;
class Label;

enum GameStage {
	MENU,
	START,
	STOREHOUSE,
	ANIMALS,
	FEED,
	EXIT,
};

void menu_playAction(Engine& eng);
void menu_exitAction(Engine& eng);

void start_storehouseAction(Engine& eng);
void start_animalsAction(Engine& eng);
void start_feedAction(Engine& eng);
void start_backAction(Engine& eng);

void storehouse_HayAddAction(Engine& eng);
void storehouse_GrainAddAction(Engine& eng);
void storehouse_VeggiesAddAction(Engine& eng);
void storehouse_backAction(Engine& eng);

void animals_addCowAction(Engine& eng);
void animals_addPigAction(Engine& eng);
void animals_addChickenAction(Engine& eng);
void animals_backAction(Engine& eng);

void feed_feedAllAction(Engine& eng);
void feed_backAction(Engine& eng);


const COORD g_coord{ 20,0 };
const short g_x = 20;
const short g_y = 0;
const std::vector<std::string> c_menuButtons = { "PLAY", "EXIT" };
const std::vector<COORD> c_menuBtnsCoord{ {15,3}, {15,4} };
const std::vector<void(*)(Engine&)> c_menuActions{ menu_playAction, menu_exitAction };
const std::vector<std::string> c_menuText{ "" };
const std::vector<COORD> c_menuTextCoord{ {15,0} };
const std::vector<std::string> c_startButtons = { "STOREHOUSE", "ANIMALS", "FEED", "BACK" };
const std::vector<COORD> c_startBtnsCoord{ {15,3}, {15,4}, {15,5}, {15,6} };
const std::vector<void(*)(Engine&)> c_startActions{ start_storehouseAction, start_animalsAction, start_feedAction, start_backAction };
const std::vector<std::string> c_startText{ "Money:", "Hay:", "Grain:", "Veggies:" };
const std::vector<COORD> c_startTextCoord{ {0,0}, {12,0},{22,0},{34,0} };
const std::vector<COORD> c_startLabelsCoord{ {7,0}, {17,0}, {29,0}, {43,0} };
const std::vector<std::string> c_storehouseText{"Money:", "Hay:", "Grain:", "Veggies:" };
const std::vector<COORD> c_storehouseTextCoord{ {15,0}, {5,3}, {5,4}, {5,5} };
const std::vector<std::string> c_storehouseButtons{ "ADD","ADD","ADD", "BACK" };
const std::vector<COORD> c_storehouseBtnsCoord{ {20,3},{20,4},{20,5},{15,6} };
const std::vector<COORD> c_storehouseLabelsCoord{ {24,0}, {14,3},{14,4},{14,5} };
const std::vector<void(*)(Engine&)> c_storehouseActions{ storehouse_HayAddAction, storehouse_GrainAddAction, storehouse_VeggiesAddAction, storehouse_backAction };
const std::vector<std::string> c_animalsText{ "Money:", "Hay:", "Grain:", "Veggies:"};
const std::vector<COORD> c_animalsTextCoord{ {0,0}, {12,0},{22,0},{34,0} };
const std::vector<std::string> c_animalsButtons{ "ADD COW", "ADD PIG", "ADD CHICKEN", "BACK"};
const std::vector<COORD> c_animalsBtnsCoord{ {15,3}, {15,4}, {15,5}, {15,6} };
const std::vector<void(*)(Engine&)> c_animalsActions{ animals_addCowAction, animals_addPigAction, animals_addChickenAction, animals_backAction };
const std::vector<COORD> c_animalsLabelsCoord{ {7,0}, {17,0}, {29,0}, {43,0} };
const std::vector<std::string> c_feedText{ "Money:", "Hay:", "Grain:", "Veggies:" };
const std::vector<COORD> c_feedTextCoord{ {0,0}, {12,0},{22,0},{34,0} };
const std::vector<COORD> c_feedLabelsCoord{ {7,0}, {17,0}, {29,0}, {43,0} };
const std::vector<std::string> c_feedButtons{ "FEED", "BACK" };
const std::vector<COORD> c_feedBtnsCoord{ {15,5}, {15,6} };
const std::vector<void(*)(Engine&)> c_feedActions{feed_feedAllAction, feed_backAction  };

class Engine
{
public:
	void init();
	void start()const;
	void pollEvents();
	void gameBehavior();

	bool quitGame()const;
	void setgameStage(int stage);
	bool addFood(int pos);
	bool addCow();
	bool addPig();
	bool addChicken();
	void feed();

	void print()const;

private:
	int gameStage_ = 0;
	std::vector<Page> pages_;

	Farm farm;
	int money_ = 1000;
	//std::vector<int&> food;
	//std::vector<int> food_{ 100,100,100 };
	//std::vector<std::string> animals_{};

	void initPages();
	Page createPage(int stage);
	std::vector<Button> createButtons(const std::vector<COORD>& coords, const std::vector<std::string>& buttonsText, const std::vector<void (*)(Engine&)>& actions);
	std::vector<Text> createText(const std::vector<COORD>& coords, const std::vector<std::string>& texts);
	std::vector<Label> createLabels(const std::vector<COORD>& coords, const std::vector<const int*>& values);
};

