#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <fstream>
#include <string>
import State_Machine;
#include "Scene.h"
#include <filesystem>
#include <thread>
#include "GameControler.h"
#include "Auction.h"
//#include "Spritesheet.h";

namespace engine {

	class GameEngine {

		//Class atributes

		//Window
		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		sf::Event ev;
		std::string resolution;

		//Scene
		bool isGameActive;
		sf::Sprite background;
		sf::Texture backgrTexture;

		//Font parameters
		sf::Font font;
		int fontSize;

		//Scene
		Scene* scene;

		//Game Controler
		GameControler* _game;

		Spritesheet s;

		void startGame(deckVersion version, GameSettings settings);

		GameEngine();

	public:

		static std::filesystem::path textureLocalisation;

		//Constructor and Destructor
		GameEngine(GameEngine&) = delete;
		GameEngine(GameEngine&&) = delete;
		GameEngine& operator=(GameEngine&) = delete;

		~GameEngine();

		static GameEngine& getInstance();

		//Main functions
		void update();

		void render();

		//Minor functions
		void pollEvent();

		//Accesors
		const bool running();

		//interface elements for commands
		void changeScene(std::filesystem::path sceneSource);


	};
}



