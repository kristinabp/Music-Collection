#include "LogInCommand.h"

LogInCommand::LogInCommand(System& receiver) :receiver(receiver)
{
}

void LogInCommand::execute()
{
	receiver.login(parameters[1], parameters[2]);
}

void LogInCommand::unexecute()
{
}

std::string LogInCommand::toString()
{
	return "login";
}