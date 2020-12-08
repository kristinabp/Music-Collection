#include "Playlist.h"

Playlist::Playlist(const std::string& name):nameOfPlaylist(name), songs(std::vector<Song*>())
{
}

Playlist* Playlist::clone() const
{
	return new Playlist(*this);
}

std::string Playlist::getNameOfPlaylist() const
{
	return nameOfPlaylist;
}

std::vector<Song*> Playlist::getSongs() const
{
	return songs;
}

void Playlist::addSong(Song* song)
{
	bool songFound=false;
	for (int i = 0; i < songs.size(); i++)
	{
		if (songs[i]->getName() == song->getName() && songs[i]->getArtist()==song->getArtist())
		{
			songFound = true;
			break;
		}
	}

	if (!songFound)
	{
		songs.push_back(song->clone());
	}
}

void Playlist::print() const
{
	std::cout << "============================\n";
	std::cout << "Playlist: " << nameOfPlaylist << '\n';
	std::cout << "============================\n";
	for (int i = 0; i < songs.size(); i++)
	{
		std::cout << i+1 << ". ";
		songs[i]->print();
	}
}

std::ostream& operator<<(std::ostream& os, const Playlist& playlist)
{
	os << playlist.nameOfPlaylist;
	return os;
}
