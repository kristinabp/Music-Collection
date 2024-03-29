#pragma once
#include "ICommand.h"
#include "System.h"

class PrintUserPlaylist :
	public ICommand
{
private:
	System& receiver;
public:
	PrintUserPlaylist(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};
