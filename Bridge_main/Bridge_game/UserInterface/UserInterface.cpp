#include "UserInterface.h"
#include "../Engine/Game_Engine.h"

ui::UserInterface::UserInterface(): _scene(nullptr) {
	this->loadTexture();
}

void ui::UserInterface::loadTexture(std::filesystem::path path)
{
	std::string fileName;
	sf::Texture texture;
	std::filesystem::path insidePath;

	for (std::filesystem::directory_entry file : std::filesystem::directory_iterator(path)) {
		if (file.is_regular_file()) {
			fileName = file.path().filename().string();
			texture.loadFromFile(file.path().string());

			_textureMap.insert(std::pair<std::string, sf::Texture>(fileName, std::move(texture)));
		}
		else {
			insidePath = file.path();
			this->loadTexture(insidePath);
		}
	}
}

ui::UserInterface& ui::UserInterface::getInstance()
{
    static UserInterface item;
    return item;
}

void ui::UserInterface::setScene(std::filesystem::path path)
{
    //declarations
    std::ifstream sceneFile(path);
    std::string itemParameters;
    std::string line;
    std::regex itemRegex("\\s*Type:\\s*([a-zA-Z]+)\\s");
    std::smatch itemMatch;
    std::regex paramRegex("\\s*([a-zA-Z-]+):\\s*([a-zA-Z0-9-]+)\\s");
    std::smatch paramMatch;
    ui::SceneBuilder* currentBuilder;
    std::string type;
	ui::UserInterface::BuilderParam builderParam;

    if (_scene != nullptr)
        delete _scene;

    _scene = new Scene();

    while (std::getline(sceneFile, line)) {
        if (std::regex_match(line, itemMatch, itemRegex)) {
			if (currentBuilder != nullptr) {
				builderParam = this->splitParam(itemParameters);
				currentBuilder->build(builderParam , _scene);
			}

            type = itemMatch[1];
            itemParameters = "";

            if (type == "Background") {
                currentBuilder = ui::SceneBackgroundBuilder::getInstance();
            }

            if (type == "Button") {
                currentBuilder = ui::SceneButtonBuilder::getInstance();

				//dodaæ tworzenie przycisku
            }

            else if (type == "Text") {
                currentBuilder = ui::SceneTextBuilder::getInstance();
            }

            else if (type == "Window") {
                currentBuilder = ui::SceneWindowBuilder::getInstance();

				//dodaæ tworzenie okna
            }

            else if (type == "Spritesheet") {
                currentBuilder = ui::SceneSpritesheetBuilder::getInstance();

				//dodaæ tworzenie spritesheet
            }
        }
        else if (std::regex_match(line, paramMatch, paramRegex)) {
            //sprawdzanie

            //mo¿e obiekt parametrów
            itemParameters += line;
        }
    }
}

sf::Texture* ui::UserInterface::getTexture(std::string textureName)
{
	return &_textureMap[textureName];
}

ui::UserInterface::BuilderParam ui::UserInterface::splitParam(std::string params)
{
	ui::UserInterface::BuilderParam builderParam;
	std::regex paramRegex("\\s*([a-zA-Z-]+):\\s*([a-zA-Z0-9-\\\"\\s_]+)");
	std::sregex_iterator paramIterator(params.begin(), params.end(), paramRegex);
	std::regex coordinatesRegex("(\\d+)x(\\d+)");
	std::regex indexRegex("\\d+");
	std::sregex_iterator end;
	std::smatch paramMatch, coordinatesMatch, textMatch;
	std::string coordStr, paramName;
	std::regex textRegex("\\s*\\\"{1}\\s*([a-zA-Z0-9\\s]*)\\s*\\\"{1}\\s*");
	std::string text;
	std::regex textureRegex("[a-zA-Z0-9_]");
	std::string textureName;

	for (auto& i = paramIterator; i != end; ++i) {
		paramMatch = *i;
		paramName = paramMatch[1].str();

		if (paramName == "vilibility") {
			if (paramMatch[2] == "true")
				builderParam.visibility = true;
			else if (paramMatch[2] == "false")
				builderParam.visibility = false;
			else
				std::cerr << "SceneBuilder: cannot read vilibility value!!!\n";

		}
		else if (paramName == "z-index") {
			if (std::regex_match(paramMatch[2].str(), indexRegex))
				builderParam.zIndex = std::stoi(paramMatch[2].str());
			else
				std::cerr << "SceneBuilder: cannot read z-index value!!!\n";
		}
		else if (paramName == "position") {
			coordStr = paramMatch[2].str();
			if (std::regex_match(coordStr, coordinatesMatch, coordinatesRegex)) {
				builderParam.position = sf::Vector2i(std::stoi(coordinatesMatch[1].str()), std::stoi(coordinatesMatch[2].str()));
			}
			else
				std::cerr << "SceneBuilder: cannot read position value!!!\n";
		}
		else if (paramName == "dimention") {
			coordStr = paramMatch[2].str();
			if (std::regex_match(coordStr, coordinatesMatch, coordinatesRegex)) {
				builderParam.dimention = sf::Vector2i(std::stoi(coordinatesMatch[1].str()), std::stoi(coordinatesMatch[2].str()));
			}
			else
				std::cerr << "SceneBuilder: cannot read dimention value!!!\n";
		}
		else if (paramName == "text") {
			text = paramMatch[2].str();

			if (std::regex_match(text, textMatch, textRegex)) {
				builderParam.text = textMatch[1].str();
			}
			std::cerr << "SceneBuilder: cannot read text value!!!\n";
		}
		else if (paramName == "texture") {
			textureName = paramMatch[2].str();

			if (std::regex_match(textureName, textureRegex)) {
				builderParam.textureName = textureName;
			}
			else
				std::cerr << "SceneBuilder: invalid texture name!!!\n";
		}

		else
			std::cerr << "SceneBuilder: unknown parameter name!!!\n";
	}

	return builderParam;
}