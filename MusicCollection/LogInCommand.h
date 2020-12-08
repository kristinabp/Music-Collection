#pragma once
#include "ICommand.h"
#include "System.h"

class LogInCommand :
	public ICommand
{
private:
	System& receiver;
public:
	LogInCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};
