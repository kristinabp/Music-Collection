#pragma once
#include "ICommand.h"
#include "System.h"

class ChangePassword :
	public ICommand
{
private:
	System& receiver;
public:
	ChangePassword(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};