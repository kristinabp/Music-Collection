#include "FilterCommand.h"

FilterCommand::FilterCommand(System& receiver) :receiver(receiver)
{
}

void FilterCommand::execute()
{
	receiver.filter(parameters[1],parameters[2]);
}

void FilterCommand::unexecute()
{
}

std::string FilterCommand::toString()
{
	return "filter";
}