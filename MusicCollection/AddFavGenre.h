#pragma once
#include "ICommand.h"
#include "System.h"

class AddFavGenre :
	public ICommand
{
private:
	System& receiver;
public:
	AddFavGenre(System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};