#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <vector>
#include "ICommand.h"

class Validator
{
private: 
	bool findComma(std::string input);
public:
	static bool validateCommand(ICommand* cmd, std::string input);
};
#endif // !VALIDATOR_H