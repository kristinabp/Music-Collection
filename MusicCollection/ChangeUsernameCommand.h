#pragma once
#include "ICommand.h"
#include "System.h"

class ChangeUsernameCommand :
	public ICommand
{
private:
	System& receiver;
public:
	ChangeUsernameCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};
