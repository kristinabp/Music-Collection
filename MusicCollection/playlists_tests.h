#include "doctest.h"
#include "Playlist.h"
#include <sstream>

TEST_CASE("Adding song to playlist")
{
    Playlist p("playlist");

    p.addSong(new Song("God is a woman", "Ariana Grande", "pop", "Womanity", Date(1, 1, 2019)));
    CHECK(p.getSongs().size()==1);
}
