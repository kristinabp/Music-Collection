#include "doctest.h"
#include "Song.h"
#include <sstream>

TEST_CASE("Song without votes")
{
    Song s("God is a woman", "Ariana Grande", "pop", "Womanity", Date(1, 1, 2019));
    CHECK(s.getRating() == 0);
}

TEST_CASE("Rated song")
{
    Song s("God is a woman", "Ariana Grande", "pop", "Womanity", Date(1, 1, 2019));
    s.rate(5);
    CHECK(s.getRating() == 5);

    s.rate(4);
    CHECK(s.getRating() == 4.5);
}

TEST_CASE("Rating song with incorrect rate")
{
    Song s("God is a woman", "Ariana Grande", "pop", "Womanity", Date(1, 1, 2019));
    s.rate(8);
    s.rate(-1);
    CHECK(s.getRating() == 0);
}
