#include "./Engine/Game_Engine.h"



int main() {
	{
		//Start Game Engine
		engine::GameEngine& game = engine::GameEngine::getInstance();


		//Game loop
		while (game.running()) {

			//Update Game
			game.update();

			//Render
			game.render();
		}
	}
}