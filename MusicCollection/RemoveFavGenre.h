#pragma once
#include "ICommand.h"
#include "System.h"

class RemoveFavGenre :
	public ICommand
{
private:
	System& receiver;
public:
	RemoveFavGenre(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};
