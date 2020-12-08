#include "RemoveFavGenre.h"

RemoveFavGenre::RemoveFavGenre(System& receiver) :receiver(receiver)
{
}

void RemoveFavGenre::execute()
{
	receiver.removeFavGenre(parameters[1]);
}

void RemoveFavGenre::unexecute()
{
}

std::string RemoveFavGenre::toString()
{
	return "removefavouritegenre";
}