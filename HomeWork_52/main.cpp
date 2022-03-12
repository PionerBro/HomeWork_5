#include "src/engine/Engine.h"

#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>


const char* title = "My Title\nMy title row 2\n";

const unsigned speed = 100;

int main() {
	Engine engine;
	engine.init();
	engine.start();
	while (!engine.quitGame()) {
		
		engine.gameBehavior();
		engine.pollEvents();

		Sleep(speed);
	}
	
	return 0;
}