#include <iostream>
#include <SDL2/SDL.h>

#include "../game.h"
#include "../scene.h"
#include "../../tests/myScene.h"

#define DEFAULT_WIDTH 1280
#define DEFAULT_HEIGHT 720

int main(int argv, char** args) {
	Game::getInstance()->initGame(DEFAULT_WIDTH,DEFAULT_HEIGHT,"Game",SDL_INIT_VIDEO,SDL_WINDOW_SHOWN);
	myScene* scene = new myScene();
	Game::getInstance()->switchScene(scene);

	if(Game::getInstance()->isInitialized()) {
		Game::getInstance()->startGame();
	}

	Game::getInstance()->closeGame();

	return 0;
}