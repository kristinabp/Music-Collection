#pragma once
#include "ICommand.h"
#include "System.h"

class RateCommand :
	public ICommand
{
private:
	System& receiver;
public:
	RateCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};
