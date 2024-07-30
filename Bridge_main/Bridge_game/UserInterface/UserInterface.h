#pragma once
#include "Scene.h"
#include <string>
#include <fstream>
#include <regex>
#include <iostream>
#include <map>
#include <filesystem>
import BuilderParam;

namespace ui {

	class UserInterface
	{
		Scene* _scene;

		std::map<std::string, sf::Texture> _textureMap;

		UserInterface(); //To do: loading settings

		void loadTexture(std::filesystem::path path);

	public:
		UserInterface(UserInterface&) = delete;
		UserInterface(UserInterface&&) = delete;

		UserInterface operator=(UserInterface&) = delete;

		static UserInterface& getInstance();

		void setScene(std::filesystem::path path);

		void addItem(ui::CanvasItem* item);
		void deleteItem(ui::CanvasItem* item); //to do: deleting by pointer
		void dropScene();

		sf::Texture* getTexture(std::string);

		

		ui::BuilderParam splitParam(std::string params);
	};

}

