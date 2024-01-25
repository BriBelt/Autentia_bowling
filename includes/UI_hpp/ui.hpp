#ifndef PRINTING_HPP
#define PRINTING_HPP

#include "../include_1.hpp"
#include "../player_hpp/player.hpp"
#include "../game_hpp/game.hpp"

class Printing{
	private:
	public:
		//printScores(Game game);
		Printing(void);
		~Printing();
		static void	printScores(int round, std::map<std::string, Player> player);
};



#endif
