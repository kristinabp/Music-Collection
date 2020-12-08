#ifndef USER_H
#define USER_H

#include<iostream>
#include<string>
#include<vector>
#include"Playlist.h"

class User
{
private:
	std::string username;
	std::string password;
	std::string fullName;
	Date dateOfBirth;
	std::vector<std::string> favouriteGenres;
	std::vector<Playlist*> playlists;

public:
	User(const std::string& u, const std::string& p, const std::string& name, const Date& birth);
	User(const std::string& u, const std::string& p, const std::string& name, const Date& birth,
		 const std::vector<std::string>& favGenres);

	std::string getUsername()const;
	std::string getPassword()const;
	std::string getFullName()const;
	Date getDateOfBirth()const;
	std::vector<std::string> getFavouriteGenres()const;
	std::vector<Playlist*> getPlaylists()const;

	void changeUsername(const std::string& newUsername);
	void changePassword(const std::string& newPassword);
	void changeFullName(const std::string& newFullName);
	void changeDateOfBirth(const Date& newDateOfBirth);
	void removeFavGenre(const std::string& genre);
	void addFavGenre(const std::string& genre);

	void createPlaylist(Playlist* playlist);
	void removePlaylist(Playlist* playlist);
	void addSongToPlaylist(std::string pl, Song* song);

	void savePlaylists(std::ofstream& os);
	void save(std::ofstream& os);
	void print()const;
};
#endif // !USER_H