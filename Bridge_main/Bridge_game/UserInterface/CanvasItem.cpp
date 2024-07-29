#include "CanvasItem.h"

//ui::CanvasItem::CanvasItem(): _visibility(true), _zIndex(0), _position(0, 0), _dimention(0, 0), _sprite() {}

ui::CanvasItem::CanvasItem(sf::Vector2i pos, sf::Texture* texture, engine::EngineItem* engineItem, sf::Vector2i dimention, int zIndex, bool visibility):
	_visibility(visibility), _zIndex(zIndex), _sprite(*texture), _position(pos), _dimention(dimention)
{
	if (dimention != sf::Vector2i(0, 0)) {
		_dimention.x = texture->getSize().x;
		_dimention.y = texture->getSize().y;
	}
}



void ui::CanvasItem::setvisibility(bool value)
{
	_visibility = value;
}

bool ui::CanvasItem::getvisibility()
{
	return _visibility;
}

void ui::CanvasItem::setPosition(sf::Vector2i pos)
{
	_position = pos;
}

sf::Vector2i ui::CanvasItem::getPosition()
{
	return _position;
}

void ui::CanvasItem::setZIndex(int z)
{
	_zIndex = z;
}

int ui::CanvasItem::getZIndex()
{
	return _zIndex;
}



void ui::CanvasItem::setDimention(sf::Vector2i dim)
{
	_dimention = dim;
}

sf::Vector2i ui::CanvasItem::getDimention()
{
	return _dimention;
}

//void ui::CanvasItem::setText(std::string text)
//{
//	_canvasText = new CanvasText(text);
//}
//
//std::string ui::CanvasItem::getText()
//{
//	return _canvasText->getText();
//}

ui::CanvasText::CanvasText(std::string text, sf::Vector2i pos, sf::Font font, int fontSize):
	_text(sf::String(text), font, fontSize), _content(text)
{}

void ui::CanvasText::setText(std::string text)
{
	_content = text;
	_text.setString(sf::String(text));
}

std::string ui::CanvasText::getText()
{
	return _content;
}

void ui::CanvasText::render(sf::RenderWindow* window)
{
	window->draw(_text);
}

void ui::CanvasSprite::setTexture(sf::Texture* texture)
{
	_sprite.setTexture(*texture);
}

void ui::CanvasSprite::render(sf::RenderWindow* window)
{
	window->draw(_sprite);
}