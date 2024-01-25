#include "../../includes/checkers_hpp/checker.hpp"

//Function checks number of players must be less or equal than 4
bool ParseInput::check_num_players(std::string num_players_str)
{
	int	num_players;

	try
	{
		num_players = std::stoi(num_players_str);
		if (num_players < 0 || num_players > 4)
			return (false);
		return (true);
	}
	catch (const std::invalid_argument &)
	{
		return (false);
	}
}

//Function Verify if the string is printable and less than 10 characters
bool ParseInput::check_name_players(std::string &name)
{
	if (name.size() > 10)
		return (false);
	for (size_t i = 0; i < name.size(); i++)
	{
		if (!isprint(name[i]) || name[i] == ' ')
			return (false);
	}
	return (true);
}

//Function check if the round has a correct score (a + b <= 10)
bool ParseInput::check_correct_round(std::string a_str, std::string b_str)
{
	int	a;
	int	b;
	try
	{
		a = std::stoi(a_str);
		b = std::stoi(b_str);
		if ((a + b > 10) && (a < 0 && b < 0))
			return (false);
		return (true);
	}
	catch(const std::invalid_argument &)
	{
		return (false);
	}
}

//Function check if the shoot has a correct score (a >= 0 && a <= 10)
bool ParseInput::check_correct_shoot(std::string a_str)
{
	int	a;

	try
	{
		a = std::stoi(a_str);
		if (!isnumber(a) && (a < 0 && a > 10))
			return (false);
		return (true);
	}
	catch (const std::invalid_argument &)
	{
		return (false);
	}
}
