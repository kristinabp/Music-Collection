#include "Validator.h"

bool Validator::findComma(std::string input)
{
	return false;
}

bool Validator::validateCommand(ICommand* cmd, std::string input)
{
	std::vector<std::string> words;
	std::string current;
	int i = 0;
	while (i < input.size())
	{
		while (i < input.size() && input[i] != ',')
		{
			current.push_back(input[i]);
			i++;
		}
		words.push_back(current);
		current = "";
		i++;
	}

	if (words[0] == "start")
	{
		//input --> start
		if (words[0] == cmd->toString() && words.size() == 1)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "login")
	{
		//input --> login username password
		if (words[0] == cmd->toString() && words.size() == 3)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "signup")
	{
		//input --> signup username password fullName day month year
		if (words[0] == cmd->toString() && words.size() == 7)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "logout")
	{
		//input --> logot
		if (words[0] == cmd->toString() && words.size() == 1)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "changeusername")
	{
		//input --> changeusername newUsername
		if (words[0] == cmd->toString() && words.size() == 2)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "changepassword")
	{
		//input --> changepassword password
		if (words[0] == cmd->toString() && words.size() == 2)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "changedateofbirth")
	{
		//input --> changedateofbirth day month year
		if (words[0] == cmd->toString() && words.size() == 4)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "changename")
	{
		//input --> changename fullName
		if (words[0] == cmd->toString() && words.size() == 2)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "addfavouritegenre")
	{
		//input --> addfavouritegenre genre
		if (words[0] == cmd->toString() && words.size() == 2)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "removefavouritegenre")
	{
		//input --> removefavouritegenre genre
		if (words[0] == cmd->toString() && words.size() == 2)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "help")
	{
		//input --> help
		if (words[0] == cmd->toString() && words.size() == 1)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "printuserplaylist")
	{
		//input --> printuserplaylist playlistname
		if (words[0] == cmd->toString() && words.size() == 2)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "addsong")
	{
		//input --> addsong playlist name artist genre album day month year
		if (words[0] == cmd->toString() && words.size() == 9)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "addplaylist")
	{
		//input --> addplaylist playlist
		if (words[0] == cmd->toString() && words.size() == 2)
		{
			return true;
		}
		else return false;
	}
	else if (words[0] == "removeplaylist")
	{
		//input --> removeplaylist playlist
		if (words[0] == cmd->toString() && words.size() == 2)
		{
			return true;
		}
		else return false;
	}
}