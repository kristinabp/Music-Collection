#include "PrintUserPlaylist.h"

PrintUserPlaylist::PrintUserPlaylist(System& receiver) :receiver(receiver)
{
}

void PrintUserPlaylist::execute()
{
	receiver.printUserPlaylist(parameters[1]);
}

void PrintUserPlaylist::unexecute()
{
}

std::string PrintUserPlaylist::toString()
{
	return "printuserplaylist";
}