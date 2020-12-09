#pragma once
#include "ICommand.h"
#include "System.h"

class RemovePlaylist :
	public ICommand
{
private:
	System& receiver;
public:
	RemovePlaylist(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};
