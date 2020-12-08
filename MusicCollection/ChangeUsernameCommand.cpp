#include "ChangeUsernameCommand.h"

ChangeUsernameCommand::ChangeUsernameCommand(System& receiver) :receiver(receiver)
{
}

void ChangeUsernameCommand::execute()
{
	receiver.changeUsername(parameters[1]);
}

void ChangeUsernameCommand::unexecute()
{
}

std::string ChangeUsernameCommand::toString()
{
	return "changeusername";
}