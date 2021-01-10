#include "PrintUserPlaylist.h"

PrintUserPlaylist::PrintUserPlaylist(System& receiver) :receiver(receiver)
{
}

void PrintUserPlaylist::execute()
{
	receiver.printUserPlaylist();
}

void PrintUserPlaylist::unexecute()
{
}

std::string PrintUserPlaylist::toString()
{
	return "printuserplaylist";
}