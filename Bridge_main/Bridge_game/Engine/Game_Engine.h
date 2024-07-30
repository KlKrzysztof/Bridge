#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <fstream>
#include <string>
//import State_Machine;
//#include "Scene.h"
#include <filesystem>
#include <thread>
//#include "GameControler.h"
//#include "Auction.h"
//#include "Spritesheet.h";
#include "../UserInterface/UserInterface.h"
#include "EngineItem.h"

namespace engine {

	class GameEngine {

		//Class atributes

		//Window
		sf::RenderWindow* _window;
		sf::VideoMode _videoMode;
		sf::Event _ev;
		std::string _resolution;

		std::vector<engine::EngineItem*> _engineItem;

		/*
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
		*/

		//void startGame(deckVersion version, GameSettings settings);

		GameEngine(); // to do: loading settings

	public:

		inline static std::filesystem::path _textureLocalisation = "../Texture/";;

		//Constructor and Destructor
		GameEngine(GameEngine&) = delete;
		GameEngine(GameEngine&&) = delete;
		GameEngine& operator=(GameEngine&) = delete;

		//~GameEngine();

		static GameEngine& getInstance() {
			static engine::GameEngine item;
			return item;
		}

		//Main functions
		void update();

		void render();

		//Minor functions
		//void pollEvent();

		//Accesors
		const bool running();

		//Interface elements for commands
		//void changeScene(std::filesystem::path sceneSource);

		//Engine items manipulation
		static void addItem(engine::EngineItem* item);
	};
}

