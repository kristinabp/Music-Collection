#include "ChangePassword.h"

ChangePassword::ChangePassword(System& receiver) :receiver(receiver)
{
}

void ChangePassword::execute()
{
	receiver.changePassword(parameters[1]);
}

void ChangePassword::unexecute()
{
}

std::string ChangePassword::toString()
{
	return "changepassword";
}