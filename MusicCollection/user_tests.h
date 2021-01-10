#include "doctest.h"
#include "User.h"
#include <sstream>

TEST_CASE("Creating user with no favourite genres and then adding one")
{
    User u1("kristinabp", "123456", "Kristina Popova", Date(5, 9, 1999));
    CHECK(u1.getFavouriteGenres().size() == 0);

    u1.addFavGenre("pop");
    CHECK(u1.getFavouriteGenres().size() == 1);
}

TEST_CASE("Creating user with favourite genres and then adding new one")
{
    User u1("kristinabp", "123456", "Kristina Popova", Date(5, 9, 1999), {"R&B","classic"});
    CHECK(u1.getFavouriteGenres().size() == 2);

    u1.addFavGenre("pop");
    CHECK(u1.getFavouriteGenres().size() == 3);
}

TEST_CASE("Removing favourite genre")
{
    User u1("kristinabp", "123456", "Kristina Popova", Date(5, 9, 1999), { "R&B","classic" });
    CHECK(u1.getFavouriteGenres().size() == 2);

    u1.removeFavGenre("R&B");
    CHECK(u1.getFavouriteGenres().size() == 1);
    CHECK(u1.getFavouriteGenres()[0] == "classic");
}

TEST_CASE("Removing not existing favourite genre")
{
    User u1("kristinabp", "123456", "Kristina Popova", Date(5, 9, 1999), { "R&B","classic" });

    u1.removeFavGenre("pop");
    CHECK(u1.getFavouriteGenres().size() == 2);
}

TEST_CASE("Creating new playlist")
{
    User u1("kristinabp", "123456", "Kristina Popova", Date(5, 9, 1999), { "R&B","classic" });
    u1.createPlaylist(new Playlist("playlist1"));
    CHECK(u1.getPlaylists().size() == 1);
    CHECK(u1.getPlaylists()[0]->getNameOfPlaylist() == "playlist1");
}

TEST_CASE("Creating existing playlist")
{
    User u1("kristinabp", "123456", "Kristina Popova", Date(5, 9, 1999), { "R&B","classic" });
    u1.createPlaylist(new Playlist("playlist1"));
    u1.createPlaylist(new Playlist("playlist1"));
    CHECK(u1.getPlaylists().size() == 1);
    CHECK(u1.getPlaylists()[0]->getNameOfPlaylist() == "playlist1");
}

TEST_CASE("Removing playlist")
{
    User u1("kristinabp", "123456", "Kristina Popova", Date(5, 9, 1999), { "R&B","classic" });
    Playlist p("playlist1");
    u1.createPlaylist(&p);
    u1.removePlaylist(&p);
    CHECK(u1.getPlaylists().size()==0);
}

TEST_CASE("Removing not existing playlist")
{
    User u1("kristinabp", "123456", "Kristina Popova", Date(5, 9, 1999), { "R&B","classic" });
    Playlist p1("playlist1");
    Playlist p2("playlist2");
    u1.createPlaylist(&p1);
    u1.removePlaylist(&p2);
    CHECK(u1.getPlaylists().size() == 1);
}

TEST_CASE("Adding song to playlist")
{
    User u1("kristinabp", "123456", "Kristina Popova", Date(5, 9, 1999), { "R&B","classic" });
    Playlist p1("playlist1");
    u1.createPlaylist(&p1);
    u1.addSongToPlaylist("playlist1", new Song("God is a woman", "Ariana Grande", "pop", "Womanity", Date(1, 1, 2019)));
    CHECK(u1.getPlaylists()[0]->getSongs().size() == 1);
}

TEST_CASE("Adding existing song to playlist")
{
    User u1("kristinabp", "123456", "Kristina Popova", Date(5, 9, 1999), { "R&B","classic" });
    Playlist p1("playlist1");
    u1.createPlaylist(&p1);
    u1.addSongToPlaylist("playlist1", new Song("God is a woman", "Ariana Grande", "pop", "Womanity", Date(1, 1, 2019)));
    u1.addSongToPlaylist("playlist1", new Song("God is a woman", "Ariana Grande", "pop", "Womanity", Date(1, 1, 2019)));
    CHECK(u1.getPlaylists()[0]->getSongs().size() == 1);
}

TEST_CASE("Changing user's info")
{
    User u1("kristinabp", "123456", "Kristina Popova", Date(5, 9, 1999), { "R&B","classic" });

    u1.changeUsername("kristina");
    CHECK(u1.getUsername() == "kristina");

    u1.changePassword("654321");
    CHECK(u1.getPassword() == "654321");

    u1.changeFullName("KP");
    CHECK(u1.getFullName() == "KP");

    u1.changeDateOfBirth(Date(5, 9, 2000));
    CHECK(u1.getDateOfBirth() == Date(5, 9, 2000));
}