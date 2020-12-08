#include "Invoker.h"

Invoker::Invoker() : receiver(new System())
{
	commands.push_back(new LogInCommand(*receiver));
	commands.push_back(new SignUpCommand(*receiver));
	commands.push_back(new StartCommand(*receiver));
	commands.push_back(new LogOutCommand(*receiver));
	commands.push_back(new ChangeUsernameCommand(*receiver));
	commands.push_back(new ChangePassword(*receiver));
	commands.push_back(new ChangeBirth(*receiver));
	commands.push_back(new ChangeName(*receiver));
	commands.push_back(new AddFavGenre(*receiver));
	commands.push_back(new RemoveFavGenre(*receiver));
	commands.push_back(new HelpCommand(*receiver));
	commands.push_back(new PrintUserPlaylist(*receiver));

}

Invoker::Invoker(ICommand* command) : receiver(new System())
{
	commands.push_back(command);
}

Invoker::~Invoker()
{
}

void Invoker::executeCommand(std::string input)
{

	for (ICommand* cmd : commands)
	{
		if (Validator::validateCommand(cmd, input))
		{
			cmd->addParameters(input);
			cmd->execute();
			return;
		}
	}

	std::cout << "Incorrect command.Try again.\n";
}
