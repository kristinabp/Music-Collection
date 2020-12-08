#include "AddFavGenre.h"

AddFavGenre::AddFavGenre(System& receiver) :receiver(receiver)
{
}

void AddFavGenre::execute()
{
	receiver.addFavGenre(parameters[1]);
}

void AddFavGenre::unexecute()
{
}

std::string AddFavGenre::toString()
{
	return "addfavouritegenre";
}