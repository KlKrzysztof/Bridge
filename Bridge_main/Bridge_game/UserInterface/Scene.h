#pragma once
#include <SFML/Graphics.hpp>
#include "CanvasItem.h"
#include <filesystem>
#include <regex>

namespace ui {

	class UserInterface::BuilderParam;

	class Scene
	{
		//Scene objects
		std::vector<CanvasItem*> _sceneItems;

		//Texts
		std::vector<sf::Text> _sceneTexts;

		std::vector < Link<Window, ListButton>> _windowLinks;

		//Pointer on font from Game Engine
		sf::Font* _font;
		int* _fontSize;

		//Window Resolution
		sf::Vector2u _resolution;

		unsigned int _center;
		unsigned int _leftColumn;
		unsigned int _rightColumn;

		//Creating objects on scene
		//void setObject(std::vector<std::string> properties);
		//inline unsigned int getPredefPosition(std::string predef);
	public:

		//Load scene
		Scene(/*std::filesystem::path fileName, sf::Font* font, int* fontSize, sf::Vector2u resolution*/);

		//Delete elements
		~Scene();

		//Updating elements on scene // mo¿e lepiej, ¿eby GE siê tym zajmowa³
		void update();

		//Rendering elements
		void renderScene(sf::RenderWindow* window);

		Command<Header, std::string, float, Tail> checkEvent(sf::Vector2i MousePos, sf::Event::EventType);

		//void commandExecutior(Command<Header, std::string, float, Tail>, int);

		//add object to scene
		void addCanvasItem(ui::CanvasItem* item);

		sf::Font* getFont();
		int* getFontSize();
		sf::Vector2u getResolution();
	};


	class SceneBuilder {
	protected:
		
		

	public:
		virtual void build(ui::UserInterface::BuilderParam buildParam, ui::Scene* scene)=0;

		static SceneBuilder* getInstance();
	};

	class SceneBackgroundBuilder: public SceneBuilder {

	public:
		virtual void build(ui::UserInterface::BuilderParam buildParam, ui::Scene* scene);

		static ui::SceneBuilder* getInstance();
	};

	class SceneWindowBuilder : public SceneBuilder {

	public:
		virtual void build(ui::UserInterface::BuilderParam buildParam, ui::Scene* scene);

		static ui::SceneBuilder* getInstance();
	};

	class SceneSpritesheetBuilder : public SceneBuilder {

	public:
		virtual void build(ui::UserInterface::BuilderParam buildParam, ui::Scene* scene);

		static ui::SceneBuilder* getInstance();
	};

	class SceneButtonBuilder : public SceneBuilder {

	public:
		virtual void build(ui::UserInterface::BuilderParam buildParam, ui::Scene* scene);

		static ui::SceneBuilder* getInstance();
	};

	class SceneTextBuilder : public SceneBuilder {

	public:
		virtual void build(ui::UserInterface::BuilderParam buildParam, ui::Scene* scene);

		static ui::SceneBuilder* getInstance();
	};
}

