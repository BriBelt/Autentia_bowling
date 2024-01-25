#ifndef GAME_HPP
#define GAME_HPP

#include <map>
#include "../../includes/player_hpp/player.hpp"

class Game {
public:
    Game(const std::string& gameName, int numPlayers);
    ~Game();

    void addPlayer(const Player& player);
    void startGame();
    void nextFrame();
    void playTurn();

    // Getters

    unsigned long getNumPlayers() const { return numPlayers; }
    std::string getName() const { return gameName; }
    int getCurrentFrame() const { return currentFrame; }

    // Setters
    void setName(const std::string& name) { gameName = name; }
    void setCurrentFrame(int frame) { currentFrame = frame; }

private:
    std::string gameName;
    unsigned long numPlayers;
    std::map<std::string, Player> playersMap;  // Map to store players by name

    int currentFrame;
    // Add any other game-related data as needed
};

#endif // GAME_HPP
