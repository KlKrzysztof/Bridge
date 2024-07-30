#include "../UserInterface/UserInterface.h"
export module Command;
import <filesystem>;

namespace engine {

	export class ICommand {
	public:
		virtual void execute() = 0;
	};

	export class ChangeSceneCommand : public ICommand {
		ui::UserInterface& _target;
		std::filesystem::path _path;

	public:
		ChangeSceneCommand(std::filesystem::path path): _target(ui::UserInterface::getInstance()), _path(path) {}

		virtual void execute() {
			_target.setScene(_path);
		}
	};


}