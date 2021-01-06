#include "Song.h"
#include "System.h"
#include "Invoker.h"

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

	/*std::vector<std::vector<bool>> m;
	std::vector<bool> c;
	for (int i = 0; i < 6; i++)
	{
		c.push_back(true);
	}
	std::vector<bool> c2;
	for (int i = 0; i < 6; i++)
	{
		c2.push_back(true);
	}
	m.push_back(c);
	m.push_back(c2);
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m[i].size(); j++)
		{
			std::cout << m[i][j] << " ";
		}
		std::cout << '\n';
	}*/
	return system("pause");
}