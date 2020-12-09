#pragma once
#include "ICommand.h"
#include "System.h"

class AddSong :
	public ICommand
{
private:
	System& receiver;
public:
	AddSong(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};