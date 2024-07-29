#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace engine {
	class EngineItem;
}

namespace ui {

	class CanvasText: public CanvasItem {
		sf::Text _text;
		std::string _content;

	public:
		CanvasText(std::string text = "", sf::Vector2i pos = sf::Vector2i(0, 0), sf::Font font = sf::Font(), int fontSize = 50);
		
		virtual void setText(std::string text);
		virtual std::string getText();

		virtual void render(sf::RenderWindow* window);
	};

	class CanvasItem
	{
		bool _visibility;
		int _zIndex;
		sf::Vector2i _position;
		sf::Vector2i _dimention;
		engine::EngineItem* _engineItem;
		ui::CanvasText* _canvasText;

	public:
		CanvasItem(sf::Vector2i pos = sf::Vector2i(0, 0), sf::Texture* texture = nullptr, engine::EngineItem* engineItem = nullptr, sf::Vector2i dimention = sf::Vector2i(0, 0), int zIndex = 0, bool visibility = true);

		virtual void render(sf::RenderWindow* window) = 0;

		virtual void setvisibility(bool value);
		virtual bool getvisibility();

		virtual void setPosition(sf::Vector2i pos);
		virtual sf::Vector2i getPosition();

		virtual void setZIndex(int z);
		virtual int getZIndex();

		//virtual void setTexture(sf::Texture* texture);
		//getTexture

		virtual void setDimention(sf::Vector2i dim);
		virtual sf::Vector2i getDimention();
		
		/*
		virtual void setText(std::string text);
		virtual std::string getText();
		*/


	};

	class CanvasSprite: public CanvasItem {
		sf::Sprite _sprite;

	public:
		virtual void setTexture(sf::Texture* texture);

		virtual void render(sf::RenderWindow* window);
	};



}

