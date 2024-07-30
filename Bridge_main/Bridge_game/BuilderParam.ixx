#include <SFML/Graphics.hpp>
export module BuilderParam;
import <string>;

export namespace ui {
	struct BuilderParam {
		bool visibility;
		int zIndex;
		sf::Vector2i position;
		sf::Vector2i dimention;
		std::string text;
		std::string textureName;
	};

}