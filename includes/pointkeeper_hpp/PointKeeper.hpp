#ifndef PointKeeper_HPP
# define PointKeeper_HPP
# include <iostream>
# include "../../includes/player_hpp/player.hpp"

class PointKeeper{
	public:
		PointKeeper();
		void calc_punt(Player play, int round, int thr1, int thr2);
		void sumpunt(Player play, int round, int punt);
};


#endif
