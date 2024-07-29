#pragma once
#include "Scene.h"
#include <string>
#include <fstream>
#include <regex>
#include <iostream>
#include <map>
#include <filesystem>

namespace ui {

	class UserInterface
	{
		Scene* _scene;

		std::map<std::string, sf::Texture> _textureMap;

		UserInterface();

		void loadTexture(std::filesystem::path path = engine::GameEngine::textureLocalisation);

	public:
		UserInterface(UserInterface&) = delete;
		UserInterface(UserInterface&&) = delete;

		UserInterface operator=(UserInterface&) = delete;

		static UserInterface& getInstance();

		void setScene(std::filesystem::path path);

		void addItem();
		void deleteItem();
		void changeScene();
		void dropScene();

		sf::Texture* getTexture(std::string);

		struct BuilderParam {
			bool visibility;
			int zIndex;
			sf::Vector2i position;
			sf::Vector2i dimention;
			std::string text;
			std::string textureName;
		};

		ui::UserInterface::BuilderParam splitParam(std::string params);
	};

}

