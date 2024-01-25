// Player.cpp
#include "../../includes/player_hpp/player.hpp"

Player::Player(const std::string& name, int playerNum) : name(name), playerNum(playerNum) {
    scores.resize(10, 0);  // Initialize the vector with 10 rounds, all scores set to 0
    this->name = name;
	this->playerNum = playerNum;
	this->multiplier = 0;
	this->totalScore = 0;
	std::vector<int> firstShots(10);
	std::vector<int> secondShots(10);
	fill(firstShots.begin(), firstShots.end(), 0);
	fill(secondShots.begin(), secondShots.end(), 0);
}


std::string	Player::getName(void) const
{
	return (this->name);
}
int	Player::getFirstShots(int roundNum) const
{
	return (this->firstShots[roundNum]);
}
int	Player::getSecondShots(int roundNum) const
{
	return (this->secondShots[roundNum]);
}
int	Player::getMultiplier(void) const
{
	return (this->multiplier);
}
void	Player::setMultiplier(int value)
{
	this->multiplier = value;
}
int	Player::getPlayerNum(void) const
{
	return (this->playerNum);
}
int	Player::getTotalScore(void) const
{
	return (this->totalScore);
}

Player::~Player() {
    // Destructor implementation if needed
}


int Player::getScore(int roundNum) const {
    if (roundNum >= 1 && roundNum <= 10) {
        return scores[roundNum - 1];  // Adjust index for 1-based round number
    }
    return -1;  // Invalid round number
}



void Player::setScore(int roundNum, int score, bool secondShot) {
    // Handle special cases for strikes, spares, and the third shot in the tenth frame
    if (roundNum >= 1 && roundNum <= 10) {
        if (secondShot && roundNum < 10) {
            scores[roundNum - 1] += score;
        } else if (roundNum < 10 && scores[roundNum - 1] == 10) {
            // Handle spare in previous frame
            scores[roundNum] += score;
        } else {
            scores[roundNum - 1] = score;
        }
    }
}
