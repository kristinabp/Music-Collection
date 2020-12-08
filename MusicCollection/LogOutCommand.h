#pragma once
#include "ICommand.h"
#include "System.h"

class LogOutCommand :
	public ICommand
{
private:
	System& receiver;
public:
	LogOutCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};
