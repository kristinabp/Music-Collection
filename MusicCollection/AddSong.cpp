#include "AddSong.h"

AddSong::AddSong(System& receiver) :receiver(receiver)
{
}

void AddSong::execute()
{
	receiver.addSong(parameters[1],parameters[2],parameters[3],parameters[4],parameters[5],std::stoi(parameters[6]),
		std::stoi(parameters[7]), std::stoi(parameters[8]));
}

void AddSong::unexecute()
{
}

std::string AddSong::toString()
{
	return "addsong";
}