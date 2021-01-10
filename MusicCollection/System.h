#ifndef SYSTEM_H
#define SYSTEM_H

#include "User.h"
#include "OrderedBinaryTree.h" 
#include <fstream>
#include <stack>

class System
{
private:
	std::vector<User*> users;
	std::vector<Song*> songs;
	std::string curUser;
	std::string curPlaylist;
	std::vector<std::vector<bool>> rates;
	bool userInSystem;

	void loadSongs();
	void loadUsers();
	void loadUserPlaylists();
	void loadRates();
	std::string readFromFileHelper(const std::string& input, int pos);
	bool checkUser(const std::string& username, const std::string& password);
	bool checkUsername(const std::string& username);
	bool checkFavGenre(const std::string& genre);
	int checkSong(const std::string& n, const std::string& a);
	void update(const std::string& fileName);
	void updateSongs(const std::string& fileName);
	void updatePlaylists(const std::string& fileName);
	void updateRates();
	void updateRates2();
	void updateRates3();
	void filterByRate(int rate,OrderedBinaryTree& s);
	void filterByGenre(const std::string& genre, bool flag, OrderedBinaryTree& s);
	void filterByYear(const std::string& time,int year, OrderedBinaryTree& s);
	void filterFav(OrderedBinaryTree& s);
	void filterHelper(std::string input,std::stack<std::string> &filters, std::stack<std::string> &op);
	void filterHelper2(std::vector<Song*> fSongs,const std::string& playlistName);
	bool isChar(char c) const;

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
	bool addPlaylist(const std::string& playlist);
	void removePlaylist(const std::string& playlist);
	void rateSong(const std::string& name,int rate);
	void filter(const std::string& input, const std::string& playlistName);
	void loadPlaylist(const std::string& playlist);
	void help()const;
	void printUserPlaylist();
};
#endif // !SYSTEM_H