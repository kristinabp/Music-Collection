#ifndef SYSTEM_H
#define SYSTEM_H

#include "User.h"
#include <fstream>

class System
{
private:
	std::vector<User*> users;
	std::vector<Song*> songs;
	std::string curUser;
	bool userInSystem;

	void loadSongs();
	void loadUsers();
	void loadUserPlaylists();
	std::string readFromFileHelper(const std::string& input, int pos);
	bool checkUser(const std::string& username, const std::string& password);
	bool checkUsername(const std::string& username);
	bool checkFavGenre(const std::string& genre);
	void update(const std::string& fileName);
	void updateSongs(const std::string& fileName);
	void updatePlaylists(const std::string& fileName);

public:
	System();

	void start();
	void signup(const std::string& username, const std::string& password, const std::string& name, int day, int month,
	int year);
	void login(const std::string& username, const std::string& password);
	void logout();
	void changeUsername(const std::string& username);
	void changePassword(const std::string& password);
	void changeDateOfBirth(int day, int month, int year);
	void changeFullName(const std::string& fullName);
	void addFavGenre(const std::string& genre);
	void removeFavGenre(const std::string& genre);
	void addSong(const std::string& playlist, const std::string& name, const std::string& artist, const std::string& genre,
		const std::string& album, int day, int month, int year);
	void addPlaylist(const std::string& playlist);
	void removePlaylist(const std::string& playlist);
	void rateSong(const std::string& name,int rate);

	void help()const;
	void printUserPlaylist(const std::string& playlist);
	void print()const;
};
#endif // !SYSTEM_H