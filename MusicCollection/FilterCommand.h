#pragma once
#include "ICommand.h"
#include "System.h"

class FilterCommand :
	public ICommand
{
private:
	System& receiver;
public:
	FilterCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};