#include "Game_Engine.h"
export module Command;
import <filesystem>;

namespace engine {

	export class ICommand {
	public:
		virtual void execute() = 0;
	};

	export class ChangeSceneCommand : public ICommand {
		GameEngine& _target;
		std::filesystem::path _path;

	public:
		ChangeSceneCommand(std::filesystem::path path): _target(engine::GameEngine::getInstance()), _path(path) {}

		virtual void execute() {
			_target.changeScene(_path);
		}
	};

	export class 

}