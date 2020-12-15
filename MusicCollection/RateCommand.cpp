#include "RateCommand.h"

RateCommand::RateCommand(System& receiver) :receiver(receiver)
{
}

void RateCommand::execute()
{
	receiver.rateSong(parameters[1], std::stoi(parameters[2]));
}

void RateCommand::unexecute()
{
}

std::string RateCommand::toString()
{
	return "rate";
}