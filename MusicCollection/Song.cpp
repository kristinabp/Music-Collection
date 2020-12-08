#include "Song.h"

Song::Song(const std::string& n, const std::string& a, const std::string& g, const std::string& album,
	const Date& date) : name(n), artist(a), genre(g), album(album), dateOfRelease(date)
{
	rating = 5;
	votes = 0;
}

Song::Song(const std::string& n, const std::string& a, const std::string& g, const std::string& album, 
	const Date& date, int v, double r) : name(n), artist(a), genre(g), album(album), dateOfRelease(date),
	                                                     votes(v), rating(r)
{
}

Song* Song::clone() const
{
	return new Song(*this);
}

std::string Song::getName() const
{
	return name;
}

std::string Song::getArtist() const
{
	return artist;
}

void Song::rate(int n)
{
	votes++;
	rating = (rating + n) / votes;
}

void Song::save(std::ofstream& os)
{
	os << name << "," << artist << "," << genre << "," << album << "," << dateOfRelease << "," << votes <<
		"," << rating << '\n';
}

void Song::print() const
{
	std::cout << artist << "-" << name << ", " << genre << ", " << album << ", " << dateOfRelease << ", " << votes <<
		", " << rating << '\n';
}