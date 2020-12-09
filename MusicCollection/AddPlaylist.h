#pragma once
#include "ICommand.h"
#include "System.h"

class AddPlaylist :
	public ICommand
{
private:
	System& receiver;
public:
	AddPlaylist (System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};