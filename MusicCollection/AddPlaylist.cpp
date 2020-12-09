#include "AddPlaylist.h"

AddPlaylist::AddPlaylist(System& receiver) :receiver(receiver)
{
}

void AddPlaylist::execute()
{
	receiver.addPlaylist(parameters[1]);
}

void AddPlaylist::unexecute()
{
}

std::string AddPlaylist::toString()
{
	return "addplaylist";
}