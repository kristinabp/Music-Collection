#include "System.h"

void System::loadSongs()
{
	std::ifstream inputFile;
	inputFile.open("songs.txt", std::ios::in);

	if (inputFile.is_open())
	{
		std::string curRow;
  		while (std::getline(inputFile, curRow))
		{
			std::string name, artist, genre, album, day, month, year;
			int votes=0, curPos=0;
			double rating=0.0;

			name = readFromFileHelper(curRow, curPos);
			curPos += name.size() + 1;

			artist = readFromFileHelper(curRow, curPos);
			curPos += artist.size() + 1;

			genre = readFromFileHelper(curRow, curPos);
			curPos += genre.size() + 1;

			album = readFromFileHelper(curRow, curPos);
			curPos += album.size() + 1;

			while (curRow[curPos] != '/')
			{
				day.push_back(curRow[curPos]);
				curPos++;
			}
			curPos++;
			while (curRow[curPos] != '/')
			{
				month.push_back(curRow[curPos]);
				curPos++;
			}
			curPos++;
			while (curRow[curPos] != ',')
			{
				year.push_back(curRow[curPos]);
				curPos++;
			}
			curPos++;

			std::string temp;
			temp = readFromFileHelper(curRow, curPos);
			curPos += temp.size() + 1;
			votes = std::stoi(temp);

			std::string temp2;
			while (curPos !=curRow.size())
			{
				temp2.push_back(curRow[curPos]);
				curPos++;
			}
			rating = std::stod(temp2);

			songs.push_back(new Song(name, artist, genre, album, Date(std::stoi(day), std::stoi(month), std::stoi(year)), 
				                                                                                  votes, rating));
		}
		inputFile.close();
	}
	else std::cout << "Couldn't open " << "songs.txt"<< "\n";
}

void System::loadUsers()
{
	std::ifstream inputFile;
	inputFile.open("users.txt", std::ios::in);

	if (inputFile.is_open())
	{
		std::string curRow;
		while (std::getline(inputFile, curRow))
		{
			std::string username, password, fullName, day, month, year;
			std::vector<std::string> genres;
			int curPos = 0, genresNum=0;
			
			username = readFromFileHelper(curRow, curPos);
			curPos += username.size() + 1;

			password = readFromFileHelper(curRow, curPos);
			curPos += password.size() + 1;
			
			fullName = readFromFileHelper(curRow, curPos);
			curPos += fullName.size() + 1;

			while (curRow[curPos] != '/')
			{
				day.push_back(curRow[curPos]);
				curPos++;
			}
			curPos++;
			while (curRow[curPos] != '/')
			{
				month.push_back(curRow[curPos]);
				curPos++;
			}
			curPos++;
			while (curPos != curRow.size())
			{
				year.push_back(curRow[curPos]);
				curPos++;
			}

			std::getline(inputFile, curRow);
			genresNum = stoi(curRow);

			for (int i = 0; i < genresNum; i++)
			{
				std::getline(inputFile, curRow);
				genres.push_back(curRow);
			}

			users.push_back(new User(username, password, fullName, Date(std::stoi(day), std::stoi(month), std::stoi(year)),
				                 genres));
		}
		inputFile.close();
	}
	else std::cout << "Couldn't open " << "users.txt" << "\n";
}

void System::loadUserPlaylists()
{
	std::ifstream inputFile;
	inputFile.open("playlists.txt", std::ios::in);

	if (inputFile.is_open())
	{
		std::string curRow;
		while (std::getline(inputFile, curRow))
		{
			for (int i = 0; i < users.size(); i++)
			{
				if (curRow == users[i]->getUsername())
				{
					std::getline(inputFile, curRow);
					int numberOfPlaylists = std::stoi(curRow);
					for (int j = 0; j < numberOfPlaylists; j++)
					{
						std::getline(inputFile, curRow);
						std::string playlistName = curRow;
						std::getline(inputFile, curRow);
						int numberOfSongs = std::stoi(curRow);
						if (numberOfSongs == 0)
						{
							users[i]->createPlaylist(new Playlist(playlistName));
						}
						for (int k = 0; k < numberOfSongs; k++)
						{
							std::string songName, artist, genre, album, d, m, y, votes, rating;
							int curPos = 0;
							std::getline(inputFile, curRow);

							songName = readFromFileHelper(curRow, curPos);
							curPos += songName.size() + 1;

							artist = readFromFileHelper(curRow, curPos);
							curPos += artist.size() + 1;

							genre = readFromFileHelper(curRow, curPos);
							curPos += genre.size() + 1;

							album = readFromFileHelper(curRow, curPos);
							curPos += album.size() + 1;

							while (curRow[curPos] != '/')
							{
								d.push_back(curRow[curPos]);
								curPos++;
							}
							curPos++;
							while (curRow[curPos] != '/')
							{
								m.push_back(curRow[curPos]);
								curPos++;
							}
							curPos++;
							while (curRow[curPos] != ',')
							{
								y.push_back(curRow[curPos]);
								curPos++;
							}
							curPos++;

							votes = readFromFileHelper(curRow, curPos);
							curPos += votes.size() + 1;

							while (curPos != curRow.size())
							{
								rating.push_back(curRow[curPos]);
								curPos++;
							}
							users[i]->addSongToPlaylist(playlistName, new Song(songName, artist, genre, album, 
								Date(std::stoi(d),std::stoi(m),std::stoi(y)), std::stoi(votes), std::stod(rating)));
						}
					}
				}
			}
		}
		inputFile.close();
	}
	else std::cout << "Couldn't open " << "playlists.txt" << "\n";
}

void System::loadRates()
{
	std::ifstream inputFile;
	inputFile.open("rates.txt", std::ios::in);

	if (inputFile.is_open())
	{
		std::string curRow;;
		while (std::getline(inputFile, curRow))
		{
			std::vector<bool> r;
			for (char c : curRow)
			{
				if (c != '\t')
				{
					if (c == '0') r.push_back(false);
					else r.push_back(true);
				}
			}
			rates.push_back(r);
		}

		inputFile.close();
	}
	else std::cout << "Couldn't open " << "rates.txt" << "\n";
}

std::string System::readFromFileHelper(const std::string& input, int pos)
{
	std::string output;
	while (input[pos] != ',')
	{
		output.push_back(input[pos]);
		pos++;
	}
	return output;
}

bool System::checkUser(const std::string& username, const std::string& password)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i]->getUsername() == username && users[i]->getPassword() == password)
		{
			return true;
		}
	}

	return false;
}

bool System::checkUsername(const std::string& username)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i]->getUsername() == username)
		{
			return true;
		}
	}

	return false;
}

bool System::checkFavGenre(const std::string& genre)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i]->getUsername() == curUser)
		{
			for (int j = 0; j < users[i]->getFavouriteGenres().size(); j++)
			{
				if (users[i]->getFavouriteGenres()[j] == genre)
				{
					return false;
				}
			}
			break;
		}
	}

	return true;
}

void System::update(const std::string& fileName)
{
	if (std::ifstream(fileName).good())
	{
		std::ofstream ofs(fileName);

		for (int i = 0; i < users.size(); i++)
		{
			users[i]->save(ofs);
		}
		ofs.close();
	}
}

void System::updateSongs(const std::string& fileName)
{
	if (std::ifstream(fileName).good())
	{
		std::ofstream ofs(fileName);

		for (int i = 0; i < songs.size(); i++)
		{
			songs[i]->save(ofs);
		}
		ofs.close();
	}
}

void System::updatePlaylists(const std::string& fileName)
{
	if (std::ifstream(fileName).good())
	{
		std::ofstream ofs(fileName);

		for (int i = 0; i < users.size(); i++)
		{
			users[i]->savePlaylists(ofs);
		}
		ofs.close();
	}
}

void System::updateRates()
{
	if (std::ifstream("rates.txt").good())
	{
		std::ofstream ofs("rates.txt");

		for (int i = 0; i < rates.size(); i++)
		{
			for (int j = 0; j < songs.size(); j++)
			{
				ofs << rates[i][j] << '\t';
			}
			ofs << '\n';
		}
		ofs.close();
	}
}

void System::filterByRate(int rate,AlphabeticalSortedSongs &s)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (curUser == users[i]->getUsername())
		{
			for (int j = 0; j < songs.size(); j++)
			{
				if (songs[j]->getRating() >= rate)
				{
					s.insert(songs[j]);
				}
			}
		}
	}
}

void System::filterHelper(std::string input,std::stack<std::string>& filters, std::stack<std::string>& operations)
{
	std::string curFilter;
	std::string curOp;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= 'a' && input[i] <= 'z')
		{
			curFilter.push_back(input[i]);
		}
		else if (input[i] == '&')
		{
			filters.push(curFilter);
			curFilter = "";
			curOp.push_back(input[i]);
			curOp.push_back(input[++i]);
			operations.push(curOp);
			curOp = "";
		}
		else if (input[i] == '|')
		{
			filters.push(curFilter);
			curFilter = "";
			if (!operations.empty() && operations.top() == "&&")
			{
				std::stack<std::string> temp;
				while (!operations.empty() && operations.top() == "&&")
				{
					temp.push(operations.top());
					operations.pop();
				}
				curOp.push_back(input[i]);
				curOp.push_back(input[++i]);
				operations.push(curOp);
				curOp = "";
				while (!temp.empty())
				{
					operations.push(temp.top());
					temp.pop();
				}
			}
			else
			{
				curOp.push_back(input[i]);
				curOp.push_back(input[++i]);
				operations.push(curOp);
				curOp = "";
			}
		}
	}
	filters.push(curFilter);
	curFilter = "";
}

bool System::isChar(char c) const
{
	return c >= 'a' && c <= 'z';
}

System::System() :users(std::vector<User*>()), songs(std::vector<Song*>()), userInSystem(false), curUser(""),
rates(std::vector<std::vector<bool>>())
{
	start();
}

void System::start()
{
	loadSongs();
	loadUsers();
	loadUserPlaylists();
	loadRates();
	std::cout << "Welcome to Krisi's music player application!\n";
	std::cout << "login\t signup\n";
}

void System::signup(const std::string& username, const std::string& password, const std::string& name, int day, int month,
	int year)
{
	if (!userInSystem)
	{
		if (checkUser(username, password))
		{
			std::cout << "Sorry, but this username already exists. Try again with another username.\n";
		}
		else
		{
			std::cout << "Successfully signed up as " << username << ".\n";
			users.push_back(new User(username, password, name, Date(day, month, year)));
			userInSystem = true;
			curUser = username;
			update("users.txt");
		}
	}
	else std::cout << "ERROR:USER IN THE SYSTEM! => LOG OUT!\n";
}

void System::login(const std::string& username, const std::string& password)
{
	if (!userInSystem)
	{
		if (checkUser(username, password))
		{
			std::cout << "Successfully loged in as " << username << ".\n";
			userInSystem = true;
			curUser = username;
		}
		else std::cout << "Incorrect username or password. Please try again. \n";
	}
	else std::cout << "ERROR:USER IN THE SYSTEM! => LOG OUT!\n";
}

void System::logout()
{
	if (userInSystem)
	{
		std::cout << "Successfully logged out.\n";
		userInSystem = false;
		curUser = "";
	}
	else std::cout << "ERROR: NO LOGGED USER IN SYSTEM!\n";
}

void System::changeUsername(const std::string& username)
{
	if (userInSystem)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->getUsername() == curUser)
			{
				if (!checkUsername(username))
				{
					users[i]->changeUsername(username);
					update("users.txt");
					std::cout << "Successfully changed username to " << username << ".\n";
					curUser = username;
					break;
				}
				else
				{
					std::cout << "This username already exists. Try again.\n";
					break;
				}
			}
		}
	}
	else std::cout << "ERROR: NO USER IN SYSTEM!\n";
}

void System::changePassword(const std::string& password)
{
	if (userInSystem)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->getUsername() == curUser)
			{
				users[i]->changePassword(password);
				update("users.txt");
				std::cout << "Successfully changed password.\n";
				break;
			}
		}
	}
	else std::cout << "ERROR: NO USER IN SYSTEM!\n";
}

void System::changeDateOfBirth(int day, int month, int year)
{
	if (userInSystem)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->getUsername() == curUser)
			{
				users[i]->changeDateOfBirth(Date(day,month,year));
				std::cout << "Successfully changed date of birth to " << users[i]->getDateOfBirth() << ".\n";
				update("users.txt");
				break;
			}
		}
	}
	else std::cout << "ERROR: NO USER IN SYSTEM!\n";
}

void System::changeFullName(const std::string& fullName)
{
	if (userInSystem)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->getUsername() == curUser)
			{
				users[i]->changeFullName(fullName);
				update("users.txt");
				std::cout << "Successfully changed full name to " << users[i]->getFullName() << ".\n";
				break;
			}
		}
	}
	else std::cout << "ERROR: NO USER IN SYSTEM!\n";
}

void System::addFavGenre(const std::string& genre)
{
	if (userInSystem)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->getUsername() == curUser)
			{
				if (checkFavGenre(genre))
				{
					users[i]->addFavGenre(genre);
					update("users.txt");
					std::cout << "Successfully added new favourite genre " << genre << ".\n";
					break;
				}
				else std::cout << "You have already added this genre as your favourite.\n";
			}
		}
	}
	else std::cout << "ERROR: NO USER IN SYSTEM!\n";
}

void System::removeFavGenre(const std::string& genre)
{
	if (userInSystem)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->getUsername() == curUser)
			{
				if (!checkFavGenre(genre))
				{
					users[i]->removeFavGenre(genre);
					update("users.txt");
					std::cout << "Successfully removed favourite genre " << genre << ".\n";
					break;
				}
				else std::cout << "There is no favourite genre with this name.\n";
			}
		}
	}
	else std::cout << "ERROR: NO USER IN SYSTEM!\n";
}

void System::addSong(const std::string& playlist, const std::string& name, const std::string& artist, 
	const std::string& genre, const std::string& album, int day, int month, int year)
{
	if (userInSystem)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->getUsername() == curUser)
			{
				users[i]->addSongToPlaylist(playlist, new Song(name, artist, genre, album, Date(day, month, year)));
				songs.push_back(new Song(name, artist, genre, album, Date(day, month, year)));
				updateSongs("songs.txt");
				updatePlaylists("playlists.txt");
				std::cout << "Successfully added song " << artist << "-" << name << " to playlist " << playlist << ".\n";
				break;
			}
		}
	}
	else std::cout << "ERROR: NO USER IN SYSTEM!\n";
}

bool System::addPlaylist(const std::string& playlist)
{
	if (userInSystem)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->getUsername() == curUser)
			{
				if (users[i]->createPlaylist(new Playlist(playlist)))
				{
					std::cout << "Successfully created a playlist with name " << playlist << ".\n";
					updatePlaylists("playlists.txt");
					return true;
				}
				else
				{
					std::cout << "Not created a playlist with name " << playlist << ".\n";
					return false;
				}
			}
		}
		return false;
	}
	else std::cout << "ERROR: NO USER IN SYSTEM!\n";
}

void System::removePlaylist(const std::string& playlist)
{
	if (userInSystem)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->getUsername() == curUser)
			{
				users[i]->removePlaylist(new Playlist(playlist));
				std::cout << "Successfully removed a playlist with name " << playlist << ".\n";
				updatePlaylists("playlists.txt");
				break;
			}
		}
	}
	else std::cout << "ERROR: NO USER IN SYSTEM!\n";
}

void System::rateSong(const std::string& name, int rate)
{
	if (userInSystem)
	{
		if (rate > 5 || rate < 0)
		{
			std::cout << "The rate must be between 0 and 5 :).\n";
			return;
		}
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->getUsername() == curUser)
			{
				for (int j = 0; j < songs.size(); j++)
				{
					if (songs[j]->getName() == name)
					{
						if (!rates[i][j])
						{
							songs[j]->rate(rate);
							rates[i][j] = true;
							updateRates();
							updateSongs("songs.txt");
							updatePlaylists("playlists.txt");
							std::cout << "You voted for " << name << ". Current rate is " << songs[j]->getRating() << "\n";
						}
						else std::cout << "You have already voted for " << name << "\n";
					
						break;
					}
				}
				break;
			}
		}
	}
	else std::cout << "ERROR: NO USER IN SYSTEM!\n";
}

void System::filter(const std::string& input, const std::string& playlistName)
{
	if (userInSystem)
	{
		if (addPlaylist(playlistName))
		{
			std::stack<std::string> filters;
			std::stack<std::string> operations;
			AlphabeticalSortedSongs filteredSongs;
			filterHelper(input, filters, operations);
			if (filters.size() == 1)
			{
				if (filters.top() == "rate")
				{
					std::string rate;
					std::cout << "With a rating above: ";
					std::getline(std::cin, rate);
					filterByRate(std::stoi(rate), filteredSongs);
					for (int i = 0; i < filteredSongs.sizee(); i++)
					{
						addSong(playlistName, filteredSongs.getSongs()[i]->getName(), 
							filteredSongs.getSongs()[i]->getArtist(), filteredSongs.getSongs()[i]->getGenre(), 
							filteredSongs.getSongs()[i]->getAlbum(), filteredSongs.getSongs()[i]->getDateOfRelease().getDay(),
							filteredSongs.getSongs()[i]->getDateOfRelease().getMonth(),
							filteredSongs.getSongs()[i]->getDateOfRelease().getYear());
					}
				}
				else if (filters.top() == "genre")
				{

				}
				else if (filters.top() == "!genre")
				{

				}
				else if (filters.top() == "before")
				{

				}
				else if (filters.top() == "after")
				{

				}
				else if (filters.top() == "from")
				{

				}
				else if (filters.top() == "fav")
				{

				}
			}
			else {
				while (!filters.empty())
				{
					std::string filter1 = filters.top();
					filters.pop();
					std::string filter2 = filters.top();
					filters.pop();
					std::string op = operations.top();
					operations.pop();
					if (op == "||")
					{
						if (filter1 == "rate")
						{
							std::string rate;
							std::cout << "With a rating above: ";
							std::getline(std::cin, rate);
							filterByRate(std::stoi(rate), filteredSongs);
							filteredSongs.print();
						}
						else if (filter1 == "genre")
						{

						}
						else if (filter1 == "!genre")
						{

						}
						else if (filter1 == "before")
						{

						}
						else if (filter1 == "after")
						{

						}
						else if (filter1 == "from")
						{

						}
						else if (filter1 == "fav")
						{

						}

						if (filter2 == "rate")
						{
							/*std::string rate;
							std::cout << "With a rating above: ";
							std::cin.ignore();
							std::getline(std::cin, rate);
							filterByRate(std::stoi(rate));*/
						}
						else if (filter2 == "genre")
						{

						}
						else if (filter2 == "!genre")
						{

						}
						else if (filter2 == "before")
						{

						}
						else if (filter2 == "after")
						{

						}
						else if (filter2 == "from")
						{

						}
						else if (filter2 == "fav")
						{

						}
					}
					else if (op == "&&")
					{

					}
				}
			}
		}
		else std::cout << "Choose a different name for this playlist.\n";
	}
	else std::cout << "ERROR: NO USER IN SYSTEM!\n";
}

void System::help() const
{
	std::cout << "------------------------\n";
	std::cout << "Supported functionality:\n";
	std::cout << "------------------------\n";
	std::cout << "signup,<username>,<password>,<full name>,<day>,<month>,<year>	\n";
	std::cout << "login,<username>,<password>\n";
	std::cout << "logout\n";
	std::cout << "changeusername,<new username>\n";
	std::cout << "changepassword,<new password>\n";
	std::cout << "changedateofbirth,<day>,<month>,<year>\n";
	std::cout << "changefullname,<new name>\n";
	std::cout << "addfavouritegenre,<genre>\n";
	std::cout << "removefavouritegenre,<genre>\n";
	std::cout << "printuserplaylist,<name of playlist>";
	std::cout << "addsong,<playlist name>,<song name>,<artist>,<genre>,<album>,<day>,<month>,<year>\n";
	std::cout << "rate,<song name>,<rate>\n";
	std::cout << "addplaylist,<playlist name>\n";
	std::cout << "removeplaylist,<playlist name>\n";
	std::cout << "addplaylist,<playlist name>\n";
	std::cout << "help\n";
	std::cout << "";
	std::cout << "------------------------\n";
}

void System::printUserPlaylist(const std::string& playlist)
{
	if (userInSystem)
	{
		bool playlistFound = false;
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i]->getUsername() == curUser)
			{
				for (int j = 0; j < users[i]->getPlaylists().size(); j++)
				{
					if (users[i]->getPlaylists()[j]->getNameOfPlaylist() == playlist)
					{
						playlistFound = true;
						users[i]->getPlaylists()[j]->print();
						break;
					}
				}
				break;
			}
		}

		if (!playlistFound) std::cout << "No playlist with this name.\n";
	}
	else std::cout << "ERROR: NO USER IN SYSTEM!\n";
}

