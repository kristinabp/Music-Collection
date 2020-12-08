#include "ChangeName.h"

ChangeName::ChangeName(System& receiver) :receiver(receiver)
{
}

void ChangeName::execute()
{
	receiver.changeFullName(parameters[1]);
}

void ChangeName::unexecute()
{
}

std::string ChangeName::toString()
{
	return "changename";
}