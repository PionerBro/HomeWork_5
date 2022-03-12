#include "Engine.h"

void Engine::init()
{
	initPages();
	gameStage_ = ANIMALS;
	addCow();
	addChicken();
	addPig();
	farm.addFoodNumber(Food::Grain, 100);
	farm.addFoodNumber(Food::Hay, 100);
	farm.addFoodNumber(Food::Vegetables, 100);
	gameStage_ = MENU;
}

void Engine::initPages()
{
	pages_.reserve(5);
	//pages_.push_back(createPage(MENU));
	//pages_.push_back(createPage(START));
	//pages_.push_back(createPage(STOREHOUSE));
	//pages_.push_back(createPage(ANIMALS));
	//pages_.push_back(createPage(FEED));
	for (int i = 0; i < 5; ++i)
		pages_.push_back(createPage(i));
}

Page Engine::createPage(int stage)
{
	switch (stage)
	{
	case MENU:
	{
		auto btns = createButtons(c_menuBtnsCoord, c_menuButtons, c_menuActions);
		auto texts = createText(c_menuTextCoord, c_menuText);
		return Page(texts, btns, {});
	}
	case START:
	{
		auto btns = createButtons(c_startBtnsCoord, c_startButtons, c_startActions);
		auto texts = createText(c_startTextCoord, c_startText);
		auto labels = createLabels(c_startLabelsCoord, { &money_, &farm.storehouse_.getFoodRef(Food::Hay), &farm.storehouse_.getFoodRef(Food::Grain), &farm.storehouse_.getFoodRef(Food::Vegetables) });
		return Page(texts, btns, labels);
	}
	case STOREHOUSE:
	{
		auto btns = createButtons(c_storehouseBtnsCoord, c_storehouseButtons, c_storehouseActions);
		auto texts = createText(c_storehouseTextCoord, c_storehouseText);
		auto labels = createLabels(c_storehouseLabelsCoord, { &money_, &farm.storehouse_.getFoodRef(Food::Hay), &farm.storehouse_.getFoodRef(Food::Grain), &farm.storehouse_.getFoodRef(Food::Vegetables) });
		return Page(texts, btns, labels);
	}
	case ANIMALS:
	{
		auto btns = createButtons(c_animalsBtnsCoord, c_animalsButtons, c_animalsActions);
		auto texts = createText(c_animalsTextCoord, c_animalsText);
		auto labels = createLabels(c_animalsLabelsCoord, { &money_, &farm.storehouse_.getFoodRef(Food::Hay), &farm.storehouse_.getFoodRef(Food::Grain), &farm.storehouse_.getFoodRef(Food::Vegetables) });
		return Page(texts, btns, labels);
	}	
	case FEED:
	{
		auto btns = createButtons(c_feedBtnsCoord, c_feedButtons, c_feedActions);
		auto texts = createText(c_feedTextCoord, c_feedText);
		auto labels = createLabels(c_feedLabelsCoord, { &money_, &farm.storehouse_.getFoodRef(Food::Hay), &farm.storehouse_.getFoodRef(Food::Grain), &farm.storehouse_.getFoodRef(Food::Vegetables) });
		return Page(texts, btns, labels);
	}
	default:
		break;
	}
	return Page({}, {}, {});
}

std::vector<Button> Engine::createButtons(const std::vector<COORD>& coords, const std::vector<std::string>& buttonsText, const std::vector<void (*)(Engine&)>& actions)
{
	size_t size = buttonsText.size();
	std::vector<Button> btns;
	btns.reserve(size);
	for (size_t i = 0; i < size; ++i) {
		short x = coords[i].X + g_x;
		short y = coords[i].Y + g_y;
		btns.push_back(Button({ x, y }, buttonsText[i], actions[i]));
	}
	return btns;
}

std::vector<Text> Engine::createText(const std::vector<COORD>& coords, const std::vector<std::string>& texts)
{
	size_t size = texts.size();
	std::vector<Text> text;
	text.reserve(size);
	for (size_t i = 0; i < size; ++i) {
		short x = coords[i].X + g_x;
		short y = coords[i].Y + g_y;
		text.push_back(Text(texts[i], { x, y }));
	}
	return text;
}

std::vector<Label> Engine::createLabels(const std::vector<COORD>& coords, const std::vector<const int*>& values)
{
	size_t size = values.size();
	std::vector<Label> labels;
	labels.reserve(size);
	for (int i = 0; i < size; ++i) {
		short x = coords[i].X + g_x;
		short y = coords[i].Y + g_y;
		labels.push_back(Label(values[i], { x, y }));
	}
	return labels;
}

void Engine::print() const
{
	system("cls");
	pages_[gameStage_].print();
}

void Engine::pollEvents()
{
	if (GetAsyncKeyState(VK_UP)) {
		pages_[gameStage_].cursorUp();
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		pages_[gameStage_].cursorDown();
	}
	if (GetAsyncKeyState(VK_RETURN)) {
		pages_[gameStage_].getAction()(*this);
		if (gameStage_ != EXIT)
			print();
	}
}

void Engine::gameBehavior()
{
	static int b = 0;
	++b;
	if (!(b % 10)) {
		++money_;
		farm.tic();
		pages_[gameStage_].printChObjects();
	}
}

void Engine::start() const
{
	print();
}

bool Engine::quitGame() const
{
	return gameStage_ == EXIT;
}

void Engine::setgameStage(int stage)
{
	gameStage_ = stage;
	if (stage == FEED) {
		int constTextsize = static_cast<int>(c_feedText.size());
		for (int i = 0; i < farm.animals_.size(); ++i) {
			pages_[gameStage_].setText(constTextsize + (i << 1) + 1, "");
		}
	}
}

bool Engine::addFood(int pos)
{
	switch (pos)
	{
	case 0:
		if (money_ < 35)
			return false;
		money_ -= 35;
		farm.addFoodNumber(static_cast<Food>(pos), 50);
		//food_[pos] += 50;
		return true;
	case 1:
		if (money_ < 10)
			return false;
		money_ -= 10;
		farm.addFoodNumber(static_cast<Food>(pos), 20);
		//food_[pos] += 20;
		return true;
	case 2:
		if (money_ < 35)
			return false;
		money_ -= 25;
		farm.addFoodNumber(static_cast<Food>(pos), 40);
		//food_[pos] += 40;
		return true;
	default:
		return false;
	}
}

bool Engine::addCow()
{
	static int a = 1;
	if (money_ < 200)
		return false;
	money_ -= 200;
	std::string name{ "Cow" + std::to_string(a) };
	Cow* cow = new Cow(name, 35);
	farm.addAnimal(cow);
	//animals_.push_back(name);
	short y = static_cast<short>(pages_[gameStage_].getTextsSize() - c_animalsText.size() + c_animalsButtons.size() + 4);
	pages_[gameStage_].addText({g_x, y}, name);
	pages_[FEED].addText({ g_x, y }, name);
	pages_[FEED].addLabel({ g_x + 10, y }, &static_cast<Animal*>(cow)->hungerLevel_);
	pages_[FEED].addText({ g_x + 20, y }, "");
	++a;
	return true;
}

bool Engine::addPig()
{
	static int a = 1;
	if (money_ < 100)
		return false;
	money_ -= 100;
	std::string name{ "Pig" + std::to_string(a) };
	//animals_.push_back(name);
	Pig* pig = new Pig(name, 25);
	farm.addAnimal(pig);
	short y = static_cast<short>(pages_[gameStage_].getTextsSize() - c_animalsText.size() + c_animalsButtons.size() + 4);
	pages_[gameStage_].addText({ g_x, y }, name);
	pages_[FEED].addText({ g_x, y }, name);
	pages_[FEED].addLabel({ g_x + 10, y }, &static_cast<Animal*>(pig)->hungerLevel_);
	pages_[FEED].addText({ g_x + 20, y }, "");
	++a;
	return true;
}

bool Engine::addChicken()
{
	static int a = 1;
	if (money_ < 50)
		return false;
	money_ -= 50;
	std::string name{ "Chicken" + std::to_string(a) };
	//animals_.push_back(name);
	Chicken* chicken = new Chicken(name, 10);
	farm.addAnimal(chicken);
	short y = static_cast<short>(pages_[gameStage_].getTextsSize() - c_animalsText.size() + c_animalsButtons.size() + 4);
	pages_[gameStage_].addText({ g_x, y }, name);
	pages_[FEED].addText({ g_x, y }, name);
	pages_[FEED].addLabel({ g_x + 10, y }, &static_cast<Animal*>(chicken)->hungerLevel_);
	pages_[FEED].addText({ g_x + 20, y }, "");
	++a;
	return true;
}

void Engine::feed()
{
	std::vector<std::string> texts = farm.Feed();
	int constTextsize = static_cast<int>(c_feedText.size());
	for (int i = 0; i < texts.size(); ++i) {
		pages_[gameStage_].setText(constTextsize + (i<<1)+1, texts[i]);
	}
}

void menu_playAction(Engine& eng)
{
	eng.setgameStage(START);
}

void menu_exitAction(Engine& eng)
{
	eng.setgameStage(EXIT);
}

void start_storehouseAction(Engine& eng)
{
	eng.setgameStage(STOREHOUSE);
}

void start_animalsAction(Engine& eng)
{
	eng.setgameStage(ANIMALS);
}

void start_feedAction(Engine& eng)
{
	eng.setgameStage(FEED);
}

void start_backAction(Engine& eng)
{
	eng.setgameStage(MENU);
}

void storehouse_HayAddAction(Engine& eng)
{
	if (eng.addFood(0))
		eng.print();
}

void storehouse_GrainAddAction(Engine& eng)
{
	if (eng.addFood(1)) {
		eng.print();
	}
}

void storehouse_VeggiesAddAction(Engine& eng)
{
	if (eng.addFood(2))
		eng.print();
}

void storehouse_backAction(Engine& eng)
{
	eng.setgameStage(START);
}

void animals_addCowAction(Engine& eng)
{
	if (eng.addCow()) {

	}
}

void animals_addPigAction(Engine& eng)
{
	if (eng.addPig()) {

	}
}

void animals_addChickenAction(Engine& eng)
{
	if (eng.addChicken()) {

	}
}

void animals_backAction(Engine& eng)
{
	eng.setgameStage(START);
}

void feed_feedAllAction(Engine& eng)
{
	eng.feed();
}

void feed_backAction(Engine& eng)
{
	eng.setgameStage(START);
}
