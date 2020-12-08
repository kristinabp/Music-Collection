#include "ChangeBirth.h"

ChangeBirth::ChangeBirth(System& receiver) :receiver(receiver)
{
}

void ChangeBirth::execute()
{
	receiver.changeDateOfBirth(std::stoi(parameters[1]), std::stoi(parameters[2]), std::stoi(parameters[3]));
}

void ChangeBirth::unexecute()
{
}

std::string ChangeBirth::toString()
{
	return "changedateofbirth";
}