#include "LoadPlaylist.h"

LoadPlaylist::LoadPlaylist(System& receiver) :receiver(receiver)
{
}

void LoadPlaylist::execute()
{
	receiver.loadPlaylist(parameters[1]);
}

void LoadPlaylist::unexecute()
{
}

std::string LoadPlaylist::toString()
{
	return "loadplaylist";
}