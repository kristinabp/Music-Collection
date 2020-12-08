#include "SignUpCommand.h"

SignUpCommand::SignUpCommand(System& receiver) :receiver(receiver)
{
}

void SignUpCommand::execute()
{
	receiver.signup(parameters[1], parameters[2], parameters[3], std::stoi(parameters[4]), std::stoi(parameters[5]), 
		std::stoi(parameters[6]));
}

void SignUpCommand::unexecute()
{
}

std::string SignUpCommand::toString()
{
	return "signup";
}