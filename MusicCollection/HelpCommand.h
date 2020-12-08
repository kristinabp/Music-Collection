#pragma once
#include "ICommand.h"
#include "System.h"

class HelpCommand :
	public ICommand
{
private:
	System& receiver;
public:
	HelpCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};