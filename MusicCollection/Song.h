#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
#include <fstream>
#include"Date.h"

class Song
{
private:
	std::string name;
	std::string artist;
	std::string genre;
	std::string album;
	Date dateOfRelease;
	int votes;
	double rating;

public:
	Song(const std::string& n, const std::string& a, const std::string& g, const std::string& album,
		const Date& date);
	Song(const std::string& n, const std::string& a, const std::string& g, const std::string& album,
		const Date& date, int v, double r);

	Song* clone()const;

	std::string getName()const;
	std::string getArtist()const;
	double getRating()const;

	void rate(int n);

	void save(std::ofstream& os);
	void print()const;
};
#endif // !SONG_H
