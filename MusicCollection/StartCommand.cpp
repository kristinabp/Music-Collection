#include "StartCommand.h"

StartCommand::StartCommand(System& receiver) :receiver(receiver)
{
}

void StartCommand::execute()
{
	receiver.start();
}

void StartCommand::unexecute()
{
}

std::string StartCommand::toString()
{
	return "start";
}