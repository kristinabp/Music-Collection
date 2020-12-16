#include "Song.h"
#include "System.h"
#include "Invoker.h"
#include "FilteredSongs.h"


int main()
{
	/*std::cout;
	Invoker remote;
	std::string input;
	while (true)
	{
		getline(std::cin, input);
		remote.executeCommand(input);
	}*/
	FilteredSongs songs;
	songs.insert(new Song("Aa", "-", "-", "-", Date(5, 12, 2020)));
	songs.insert(new Song("Ba", "-", "-", "-", Date(5, 12, 2020)));
	songs.insert(new Song("C", "-", "-", "-", Date(5, 12, 2020)));
	songs.insert(new Song("D", "-", "-", "-", Date(5, 12, 2020)));
	songs.insert(new Song("E", "-", "-", "-", Date(5, 12, 2020)));
	songs.insert(new Song("F", "-", "-", "-", Date(5, 12, 2020)));
	songs.insert(new Song("G", "-", "-", "-", Date(5, 12, 2020)));
	songs.insert(new Song("Bbb", "-", "-", "-", Date(5, 12, 2020)));
	songs.insert(new Song("Ab", "-", "-", "-", Date(5, 12, 2020)));
	songs.prettyPrint();
	songs.print();
	return system("pause");
}