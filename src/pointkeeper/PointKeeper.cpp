#include "../../includes/pointkeeper_hpp/PointKeeper.hpp"

PointKeeper::PointKeeper()
{

}
void PointKeeper::calc_punt(Player play, int round, int thr1, int thr2)
{
	int punt = thr1 + thr2;
	int mult = play.getMultiplier();

	if (round < 9)
		sumpunt(play, round, punt);
	if (mult==1)
	{
		sumpunt(play, round-1, thr1);
		play.setMultiplier(0);
	}
	if (mult==2)
	{	
		if ( thr1 != 10)
			play.setMultiplier(1);
		sumpunt(play, round-1, punt);
		play.setMultiplier(0);
	}
	if (mult>2)
	{
		if ( thr1 != 10)
			play.setMultiplier(mult--);
		sumpunt(play, round-1, punt);
		sumpunt(play, round-2, punt);
		play.setMultiplier(mult-2);
	}
	if (thr1==10)
		play.setMultiplier(mult+2);
	else if (thr1 + thr2 == 10)
		play.setMultiplier(mult+1);
}

void PointKeeper::sumpunt(Player play, int round, int punt)
{
	play.setScore(round, play.getScore(round) + punt);
}