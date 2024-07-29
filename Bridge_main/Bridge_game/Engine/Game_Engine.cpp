#include "Game_Engine.h"

//void br::Game::Menu::changeScene(std::filesystem::path sceneSource)
//{
//	auto font = _game->scene->getFont();
//	auto fontSize = _game->scene->getFontSize();
//	delete _game->scene;
//	_game->scene = new Scene(sceneSource, font, fontSize);
//}

void br::GameEngine::startGame(deckVersion version, GameSettings settings)
{
	_game = new GameControler(scene, version, settings);
}

//Constructor and Destructor
br::GameEngine::GameEngine() :window(nullptr), ev(), videoMode(), isGameActive(false), s(300, 5, 30) {
	std::ifstream setup_file{ std::filesystem::path(".\\Setup_files\\Window.stp") };
	std::string setup;

	std::getline(setup_file, setup);

	videoMode.height = stoi(setup.substr(1, 5));
	videoMode.width = stoi(setup.substr(6, 9));

	resolution = setup.substr(1, 9);

	std::getline(setup_file, setup);

	if (!setup.compare("full_screen"))
		window = new sf::RenderWindow(videoMode, "Bridge", sf::Style::Fullscreen);
	else
		window = new sf::RenderWindow(videoMode, "Bridge", sf::Style::Titlebar | sf::Style::Close);

	backgrTexture.loadFromFile("Images/Background/Background_" + resolution + ".png");
	background.setTexture(backgrTexture);

	std::getline(setup_file, setup);
	fontSize = std::stoi(setup);
	font.loadFromFile("Fonts/PressStart2P-Regular.ttf");



	scene = new Scene(std::filesystem::path(".\\Scenes\\Main_Menu.scn"), &font, &fontSize, window->getSize());

	/*start = new Button([](){}, "Start", font, fontSize);
	start->setPosition(sf::Vector2f(1920 / 2, 1080 / 2));*/

	window->setFramerateLimit(60);
	setup_file.close();

	/*sf::Texture t;
	t.loadFromFile("Images/Buttons/Main_button.png");*/
	/*sf::Image im;
	im.loadFromFile("Images/Cards/Shuffle_animation.png");
	s.setTexture(im);
	s.setPosition(sf::Vector2u(300, 300));*/
}

br::GameEngine::~GameEngine() {
	delete window;
	delete scene;
	delete _game;
}

GameEngine& engine::GameEngine::getInstance()
{
	static engine::GameEngine item;
	return item;
}

//Main functions
void br::GameEngine::update() {
	pollEvent();

	if (isGameActive)
		_game->updateGame();
}

void br::GameEngine::render() {
	//Clear old frame
	window->clear();

	window->draw(background);

	if (isGameActive) {
		_game->renderGame(window);
	}
	else
		scene->renderScene(window);

	//Display new one
	window->display();
}


//Minor functions
void br::GameEngine::pollEvent() {
	sf::Vector2i mousePos = sf::Mouse::getPosition();
	std::filesystem::path path;
	Command<Header, std::string, float, Tail> command;

	while (window->pollEvent(ev)) {

		if (isGameActive) {
			command = _game->eventControler(mousePos, ev.type);
		}
		else {
			command = scene->checkEvent(mousePos, ev.type);
		}

		switch (command._header)//przenieœæ do update
		{
		case Header::Drop:
			if (command._tail == Tail::Window)
				window->close();
			else if (command._tail == Tail::Scene)
				delete scene;
			break;
		case Header::ChangeScene:
			path.assign(command._main);
			delete scene;
			scene = new Scene(path, &font, &fontSize, sf::Vector2u(videoMode.width, videoMode.height));
			if (path.filename() == "Game.scn") {
				isGameActive = true;
				startGame(deckVersion::second, GameSettings());//do zmiany
				_game->newGame();
			}
			else
				isGameActive = false;
			break;
		case Header::ChangeValue:
			break;
		case Header::Non:
			break;
		}
	}
}

//Accesors
const bool br::GameEngine::running() {
	return window->isOpen();
}



//void br::Game::changeScene(std::filesystem::path sceneSource)
//{
//	Scene* newScene = new Scene(sceneSource, scene->getFont(), scene->getFontSize());
//
//	delete scene;
//
//	scene = std::move(newScene);
//}




#include "Game_Engine.h"

//void br::Game::Menu::changeScene(std::filesystem::path sceneSource)
//{
//	auto font = _game->scene->getFont();
//	auto fontSize = _game->scene->getFontSize();
//	delete _game->scene;
//	_game->scene = new Scene(sceneSource, font, fontSize);
//}

void br::GameEngine::startGame(deckVersion version, GameSettings settings)
{
	_game = new GameControler(scene, version, settings);
}

//Constructor and Destructor
br::GameEngine::GameEngine() :window(nullptr), ev(), videoMode(), isGameActive(false), s(300, 5, 30) {
	std::ifstream setup_file{ std::filesystem::path(".\\Setup_files\\Window.stp") };
	std::string setup;

	std::getline(setup_file, setup);

	videoMode.height = stoi(setup.substr(1, 5));
	videoMode.width = stoi(setup.substr(6, 9));

	resolution = setup.substr(1, 9);

	std::getline(setup_file, setup);

	if (!setup.compare("full_screen"))
		window = new sf::RenderWindow(videoMode, "Bridge", sf::Style::Fullscreen);
	else
		window = new sf::RenderWindow(videoMode, "Bridge", sf::Style::Titlebar | sf::Style::Close);

	backgrTexture.loadFromFile("Images/Background/Background_" + resolution + ".png");
	background.setTexture(backgrTexture);

	std::getline(setup_file, setup);
	fontSize = std::stoi(setup);
	font.loadFromFile("Fonts/PressStart2P-Regular.ttf");



	scene = new Scene(std::filesystem::path(".\\Scenes\\Main_Menu.scn"), &font, &fontSize, window->getSize());

	/*start = new Button([](){}, "Start", font, fontSize);
	start->setPosition(sf::Vector2f(1920 / 2, 1080 / 2));*/

	window->setFramerateLimit(60);
	setup_file.close();

	/*sf::Texture t;
	t.loadFromFile("Images/Buttons/Main_button.png");*/
	/*sf::Image im;
	im.loadFromFile("Images/Cards/Shuffle_animation.png");
	s.setTexture(im);
	s.setPosition(sf::Vector2u(300, 300));*/
}

br::GameEngine::~GameEngine() {
	delete window;
	delete scene;
	delete _game;
}

//Main functions
void br::GameEngine::update() {
	pollEvent();

	if (isGameActive)
		_game->updateGame();
}

void br::GameEngine::render() {
	//Clear old frame
	window->clear();

	window->draw(background);

	if (isGameActive) {
		_game->renderGame(window);
	}
	else
		scene->renderScene(window);

	//Display new one
	window->display();
}


//Minor functions
void br::GameEngine::pollEvent() {
	sf::Vector2i mousePos = sf::Mouse::getPosition();
	std::filesystem::path path;
	Command<Header, std::string, float, Tail> command;

	while (window->pollEvent(ev)) {

		if (isGameActive) {
			command = _game->eventControler(mousePos, ev.type);
		}
		else {
			command = scene->checkEvent(mousePos, ev.type);
		}

		switch (command._header)//przenieœæ do update
		{
		case Header::Drop:
			if (command._tail == Tail::Window)
				window->close();
			else if (command._tail == Tail::Scene)
				delete scene;
			break;
		case Header::ChangeScene:
			path.assign(command._main);
			delete scene;
			scene = new Scene(path, &font, &fontSize, sf::Vector2u(videoMode.width, videoMode.height));
			if (path.filename() == "Game.scn") {
				isGameActive = true;
				startGame(deckVersion::second, GameSettings());//do zmiany
				_game->newGame();
			}
			else
				isGameActive = false;
			break;
		case Header::ChangeValue:
			break;
		case Header::Non:
			break;
		}
	}
}

//Accesors
const bool br::GameEngine::running() {
	return window->isOpen();
}

//void br::Game::changeScene(std::filesystem::path sceneSource)
//{
//	Scene* newScene = new Scene(sceneSource, scene->getFont(), scene->getFontSize());
//
//	delete scene;
//
//	scene = std::move(newScene);
//}




