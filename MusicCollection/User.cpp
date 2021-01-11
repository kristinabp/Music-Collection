#include "User.h"

User::User(const std::string& u, const std::string& p, const std::string& name, const Date& birth) :
	username(u), password(p), fullName(name), dateOfBirth(birth), favouriteGenres(std::vector<std::string>()),
	playlists(std::vector <Playlist*>())
{
}

User::User(const std::string& u, const std::string& p, const std::string& name, const Date& birth, 
	       const std::vector<std::string>& favGenres) : username(u), password(p), fullName(name), dateOfBirth(birth), 
	                                                   favouriteGenres(favGenres), playlists(std::vector <Playlist*>())
{
}

std::string User::getUsername() const
{
	return username;
}

std::string User::getPassword() const
{
	return password;
}

std::string User::getFullName() const
{
	return fullName;
}

Date User::getDateOfBirth() const
{
	return dateOfBirth;
}

std::vector<std::string> User::getFavouriteGenres() const
{
	return favouriteGenres;
}

std::vector<Playlist*> User::getPlaylists() const
{
	return playlists;
}

void User::changeUsername(const std::string& newUsername)
{
	username = newUsername;
}

void User::changePassword(const std::string& newPassword)
{
	password = newPassword;
}

void User::changeFullName(const std::string& newFullName)
{
	fullName = newFullName;
}

void User::changeDateOfBirth(const Date& newDateOfBirth)
{
	dateOfBirth = newDateOfBirth;
}

void User::removeFavGenre(const std::string& genre)
{
	bool genreFound = false;
	int atIndex;
	for (int i = 0; i < favouriteGenres.size(); i++)
	{
		if (favouriteGenres[i] == genre)
		{
			atIndex = i;
			genreFound = true;
			break;
		}
	}

	if (genreFound)
	{
		favouriteGenres.erase(favouriteGenres.begin() + atIndex);
	}
}

void User::addFavGenre(const std::string& genre)
{
	favouriteGenres.push_back(genre);
}

bool User::createPlaylist(Playlist* playlist)
{
	bool playlistExists=false;
	for (int i = 0; i < playlists.size(); i++)
	{
		if (playlists[i]->getNameOfPlaylist() == playlist->getNameOfPlaylist())
		{
			playlistExists = true;
			break;
		}
	}

	if (playlistExists)
	{
		std::cout << "Playlist exists with this name.\n";
		return false;
	}
	else
	{
		playlists.push_back(playlist->clone());
		return true;
	}
}

void User::removePlaylist(Playlist* playlist)
{
	bool playlistExists = false;
	int atIndex;
	for (int i = 0; i < playlists.size(); i++)
	{
		if (playlists[i]->getNameOfPlaylist() == playlist->getNameOfPlaylist())
		{
			playlistExists = true;
			atIndex = i;
			break;
		}
	}

	if (playlistExists)
	{
		playlists.erase(playlists.begin() + atIndex);
	}
}

void User::addSongToPlaylist(std::string pl, Song* song)
{
	bool playlistExists = false;
	int atIndex;
	for (int i = 0; i < playlists.size(); i++)
	{
		if (playlists[i]->getNameOfPlaylist() == pl)
		{
			playlistExists = true;
			atIndex = i;
			break;
		}
	}

	if (playlistExists)
	{
		playlists[atIndex]->addSong(song);
	}
	else
	{
		createPlaylist(new Playlist(pl));
		playlists[playlists.size() - 1]->addSong(song);
	}

}

void User::savePlaylists(std::ofstream& os) const
{
	os << username << '\n' << playlists.size() << '\n';
	for (int i = 0; i < playlists.size(); i++)
	{
		os << playlists[i]->getNameOfPlaylist() << '\n' << playlists[i]->getSongs().size() << '\n';
		for (int j = 0; j<playlists[i]->getSongs().size(); j++)
		{
			playlists[i]->getSongs()[j]->save(os);
		}
	}
}

void User::save(std::ofstream& os) const
{
	os << username << ',' << password << ',' << fullName << ',' << dateOfBirth << '\n';
	os << favouriteGenres.size() << '\n';
	for (int i = 0; i < favouriteGenres.size(); i++)
	{
		os << favouriteGenres[i] << '\n';
	}
}

void User::print() const
{
	std::cout << "username:" << username << '\n';
	std::cout << "password:" << password << '\n';
	std::cout << "full name:" << fullName << '\n';
	std::cout << "birth:";
	dateOfBirth.print();
	std::cout << '\n';
	if (!favouriteGenres.empty())
	{
		std::cout << "Favourite genres: \n";
		for (int i = 0; i < favouriteGenres.size(); i++)
		{
			std::cout << i+1 << ". " << favouriteGenres[i] << '\n';
		}
	}
	else std::cout << "no favourite genres.\n";

	if (!playlists.empty())
	{
		std::cout << "Playlist: \n";
		for (int i = 0; i < playlists.size(); i++)
		{
			std::cout << i+1 << ". " << playlists[i]->getNameOfPlaylist() << '\n';
			playlists[i]->print();
		}
	}
	else std::cout << "no playlists.\n";
}
