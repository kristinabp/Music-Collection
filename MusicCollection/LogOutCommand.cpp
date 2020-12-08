#include "LogOutCommand.h"

LogOutCommand::LogOutCommand(System& receiver) :receiver(receiver)
{
}

void LogOutCommand::execute()
{
	receiver.logout();
}

void LogOutCommand::unexecute()
{
}

std::string LogOutCommand::toString()
{
	return "logout";
}