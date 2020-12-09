#include "RemovePlaylist.h"

RemovePlaylist::RemovePlaylist(System& receiver) :receiver(receiver)
{
}

void RemovePlaylist::execute()
{
	receiver.removePlaylist(parameters[1]);
}

void RemovePlaylist::unexecute()
{
}

std::string RemovePlaylist::toString()
{
	return "removeplaylist";
}