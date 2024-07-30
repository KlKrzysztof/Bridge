#include "Scene.h"
#include "UserInterface.h"
#include "../Engine/Game_Engine.h"

ui::CanvasSprite* buildCanvasItem(ui::BuilderParam buildParam) {
	ui::CanvasSprite* item = new ui::CanvasSprite();

	item->setPosition(buildParam.position);

	item->setDimention(buildParam.dimention);

	item->setvisibility(buildParam.visibility);

	item->setZIndex(buildParam.zIndex);

	item->setTexture(ui::UserInterface::getInstance().getTexture(buildParam.textureName));

	return item;
}

ui::CanvasText* buildCanvasText(ui::BuilderParam buildParam) {
	ui::CanvasText* item = new ui::CanvasText();

	item->setPosition(buildParam.position);

	item->setDimention(buildParam.dimention);

	item->setvisibility(buildParam.visibility);

	item->setZIndex(buildParam.zIndex);

	item->setText(buildParam.text);

	return item;
}

void ui::SceneBackgroundBuilder::build(ui::BuilderParam buildParam, ui::Scene* scene)
{
	CanvasSprite* item = buildCanvasItem(buildParam);

	scene->addCanvasItem(item);

	//engine::GameEngine::addItem()
}

ui::SceneBuilder* ui::SceneBackgroundBuilder::getInstance()
{
	static ui::SceneBuilder* item = new SceneBackgroundBuilder();
	return item;
}

void ui::SceneWindowBuilder::build(ui::BuilderParam buildParam, ui::Scene* scene)
{
	CanvasSprite* item = buildCanvasItem(buildParam);

	//dodaæ engineItem

	scene->addCanvasItem(item);
}

ui::SceneBuilder* ui::SceneWindowBuilder::getInstance()
{
	static ui::SceneBuilder* item = new SceneWindowBuilder();
	return item;
}

void ui::SceneSpritesheetBuilder::build(ui::BuilderParam buildParam, ui::Scene* scene)
{
	CanvasSprite* item = buildCanvasItem(buildParam);

	//dodaæ engineItem

	scene->addCanvasItem(item);
}

ui::SceneBuilder* ui::SceneSpritesheetBuilder::getInstance()
{
	static ui::SceneBuilder* item = new SceneSpritesheetBuilder();
	return item;
}

void ui::SceneButtonBuilder::build(ui::BuilderParam buildParam, ui::Scene* scene)
{
	CanvasSprite* item = buildCanvasItem(buildParam);

	//dodaæ engineItem

	scene->addCanvasItem(item);
}

ui::SceneBuilder* ui::SceneButtonBuilder::getInstance()
{
	static ui::SceneBuilder* item = new SceneButtonBuilder();
	return item;
}

void ui::SceneTextBuilder::build(ui::BuilderParam buildParam, ui::Scene* scene)
{
	CanvasText* item = buildCanvasText(buildParam);

	scene->addCanvasItem(item);
}

ui::SceneBuilder* ui::SceneTextBuilder::getInstance()
{
	static ui::SceneBuilder* item = new SceneTextBuilder();
	return item;
}

ui::SceneBuilder* ui::SceneBuilder::getInstance()
{
	return nullptr;
}

ui::Scene::~Scene()
{
	for (auto& item : this->_sceneItems) {
		delete item;
	}
}

void ui::Scene::renderScene(sf::RenderWindow* window)
{
	for (auto& item : this->_sceneItems) {
		item->render(window);
	}
}

void ui::Scene::addCanvasItem(ui::CanvasItem* item)
{
	this->_sceneItems.push_back(item);
}


