// Player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>

class Player {
private:
    std::string name;
    std::vector<int> scores;  // Use a vector to store scores for each round
    std::vector<int>	firstShots;
	std::vector<int>	secondShots;
    int	multiplier;
	int	totalScore;
    int playerNum;

public:
    Player(const std::string& name, int playerNum);
    ~Player();
    std::string	getName(void) const;
	int	getFirstShots(int roundNum) const;
	int	getSecondShots(int roundNum) const;
	int	getPlayerNum(void) const;
	int	getMultiplier(void) const;
	void	setMultiplier(int value);
	int	getTotalScore(void) const;
    int getScore(int roundNum) const;
    void setScore(int roundNum, int score, bool secondShot = false);
};

#endif // PLAYER_HPP
