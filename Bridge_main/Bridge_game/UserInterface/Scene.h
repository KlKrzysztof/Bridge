#pragma once
#include <SFML/Graphics.hpp>
#include "CanvasItem.h"
#include <filesystem>
#include <regex>
//#include "../UserInterface/UserInterface.h"
import BuilderParam;

namespace ui {


	class Scene
	{
		//Scene objects
		std::vector<CanvasItem*> _sceneItems;

		//std::vector < Link<Window, ListButton>> _windowLinks;

		unsigned int _center;
		unsigned int _leftColumn;
		unsigned int _rightColumn;

		//inline unsigned int getPredefPosition(std::string predef);
	public:
		//Delete elements
		~Scene();

		//Updating elements on scene // mo¿e lepiej, ¿eby GE siê tym zajmowa³
		void update();

		//Rendering elements
		void renderScene(sf::RenderWindow* window);

		//Command<Header, std::string, float, Tail> checkEvent(sf::Vector2i MousePos, sf::Event::EventType);

		//void commandExecutior(Command<Header, std::string, float, Tail>, int);

		//add object to scene
		void addCanvasItem(ui::CanvasItem* item);
	};


	class SceneBuilder {

	public:
		virtual void build(ui::BuilderParam buildParam, ui::Scene* scene)=0;

		static SceneBuilder* getInstance();
	};

	class SceneBackgroundBuilder: public SceneBuilder {

	public:
		virtual void build(ui::BuilderParam buildParam, ui::Scene* scene);

		static ui::SceneBuilder* getInstance();
	};

	class SceneWindowBuilder : public SceneBuilder {

	public:
		virtual void build(ui::BuilderParam buildParam, ui::Scene* scene);

		static ui::SceneBuilder* getInstance();
	};

	class SceneSpritesheetBuilder : public SceneBuilder {

	public:
		virtual void build(ui::BuilderParam buildParam, ui::Scene* scene);

		static ui::SceneBuilder* getInstance();
	};

	class SceneButtonBuilder : public SceneBuilder {

	public:
		virtual void build(ui::BuilderParam buildParam, ui::Scene* scene);

		static ui::SceneBuilder* getInstance();
	};

	class SceneTextBuilder : public SceneBuilder {

	public:
		virtual void build(ui::BuilderParam buildParam, ui::Scene* scene);

		static ui::SceneBuilder* getInstance();
	};
}

