#ifndef LOADPLAYLIST_H
#define LOADPLAYLIST_H
#include "ICommand.h"
#include "System.h"

class LoadPlaylist :
	public ICommand
{
private:
	System& receiver;
public:
	LoadPlaylist (System& receiver);

	void execute();
	void unexecute();

	std::string toString();
};

#endif // !LOADPLAYLIST_H