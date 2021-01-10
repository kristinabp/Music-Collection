#ifndef INVOKER_H
#define INVOKER_H

#include"Icommand.h"
#include"LogInCommand.h"
#include"LogOutCommand.h"
#include"ChangeUsernameCommand.h"
#include"ChangePassword.h"
#include"ChangeBirth.h"
#include"ChangeName.h"
#include"AddFavGenre.h"
#include"RemoveFavGenre.h"
#include"SignUpCommand.h"
#include"HelpCommand.h"
#include"PrintUserPlaylist.h"
#include"AddSong.h"
#include"AddPlaylist.h"
#include"RemovePlaylist.h"
#include"FilterCommand.h"
#include"RateCommand.h"
#include"LoadPlaylist.h"
#include"Validator.h"
#include<vector>
#include<string>

class Invoker
{
private:
	std::vector <ICommand*> commands;
	System* receiver;

public:
	Invoker();
	Invoker(ICommand* command);
	~Invoker();

	void executeCommand(std::string input);

};
#endif // !INVOKER_H