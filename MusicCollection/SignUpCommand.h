#pragma once
#include "ICommand.h"
#include "System.h"

class SignUpCommand :
	public ICommand
{
private:
	System& receiver;
public:
	SignUpCommand(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};
