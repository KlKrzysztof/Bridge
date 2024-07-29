#include "Scene.h"
#include "UserInterface.h"

void ui::SceneBackgroundBuilder::build(ui::UserInterface::BuilderParam buildParam, ui::Scene* scene)
{
	CanvasSprite* item = new CanvasSprite();
	
	item->setPosition(buildParam.position);

	item->setDimention(buildParam.dimention);

	item->setvisibility(buildParam.visibility);

	item->setZIndex(buildParam.zIndex);

	item->setTexture(ui::UserInterface::getInstance().getTexture(buildParam.textureName));

	scene->addCanvasItem(item);
}

ui::SceneBuilder* ui::SceneBackgroundBuilder::getInstance()
{
	static ui::SceneBuilder* item = new SceneBackgroundBuilder();
	return item;
}

void ui::SceneWindowBuilder::build(ui::UserInterface::BuilderParam buildParam, ui::Scene* scene)
{
	CanvasSprite* item = new CanvasSprite();

	item->setPosition(buildParam.position);

	item->setDimention(buildParam.dimention);

	item->setvisibility(buildParam.visibility);

	item->setZIndex(buildParam.zIndex);

	item->setTexture(ui::UserInterface::getInstance().getTexture(buildParam.textureName));

	scene->addCanvasItem(item);
}
