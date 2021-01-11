#include "Song.h"
#include "System.h"
#include "Invoker.h"

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "song_tests.h"

int main()
{
	std::cout;
	Invoker remote;
	std::string input;
	while (true)
	{
		getline(std::cin, input);
		remote.executeCommand(input);
	}

	return system("pause");
}