#pragma once
#include "ICommand.h"
#include "System.h"

class ChangeBirth :
	public ICommand
{
private:
	System& receiver;
public:
	ChangeBirth(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};