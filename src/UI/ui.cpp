#include "../../includes/UI_hpp/ui.hpp"

void	setPlayerIndex(int i)
{
	std::cout << "|";
	std::cout << std::setw(1);
	std::cout << i + 1;
	std::cout << "|";
}

void	setPlayerScore(int round, Player player)
{
	for (int i = 0; i < round; i++){
		std::cout << std::setw(5);
		std::cout << player.getScore(i + 1);
		std::cout << "|";
	}
}

void	setPlayerName(std::string name)
{
	std::cout << std::setw(10);
	std::cout << name;
	std::cout << "|";
}


void	printHeader(void)
{
	std::cout << " _________________________________________________________________________ " << std::endl;
	std::cout << "|";
	std::cout << std::setw(12);
	std::cout << "Names";
	std::cout << "|";
	for (int i = 0; i < 10; i++){
		std::cout << std::setw(5);
		std::cout << i + 1;
		std::cout << "|";
	}
	std::cout <<   std::endl;
	std::cout << " _________________________________________________________________________ " << std::endl;
}

void	Printing::printScores(int round, std::map<std::string, Player> player)
{
	printHeader();
	for (int i = 0; i < round; i++){
		for (std::map<std::string, Player>::iterator it = player.begin(); it != player.end(); it++){
			setPlayerIndex(i);
			setPlayerName(it->first);
			setPlayerScore(round, it->second);
			std::cout << std::endl;
			std::cout << " _________________________________________________________________________ " << std::endl;
			i++;
		}
	}
}

