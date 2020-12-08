#pragma once
#include "ICommand.h"
#include "System.h"

class StartCommand :
	public ICommand
{
private:
	System& receiver;
public:
	StartCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};
