#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include<vector>

class Playlist
{
private:
	std::string nameOfPlaylist;
	std::vector<Song*> songs;

public:
	Playlist(const std::string& name);

	friend std::ostream& operator<<(std::ostream& os, const Playlist& playlist);
	Playlist* clone()const;

	std::string getNameOfPlaylist()const;
	std::vector<Song*> getSongs() const;

	void addSong(Song* song);

	void filterPlaylistByRating(double value);
	void filterPlaylistByGenre(std::string genre);
	void filterPlaylistByYear(int year);
	void print()const;

};

#endif // !PLAYLIST_H
