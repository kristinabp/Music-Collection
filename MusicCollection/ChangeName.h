#pragma once
#include "ICommand.h"
#include "System.h"

class ChangeName :
	public ICommand
{
private:
	System& receiver;
public:
	ChangeName(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};