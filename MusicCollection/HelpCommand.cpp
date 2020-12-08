#include "HelpCommand.h"

HelpCommand::HelpCommand(System& receiver) :receiver(receiver)
{
}

void HelpCommand::execute()
{
	receiver.help();
}

void HelpCommand::unexecute()
{
}

std::string HelpCommand::toString()
{
	return "help";
}