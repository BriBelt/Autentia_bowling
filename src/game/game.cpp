#include <iostream>
#include <unistd.h>
#include "../../includes/game_hpp/game.hpp"
#include "../../includes/UI_hpp/ui.hpp"

Game::Game(const std::string& name, int numPlayers) : gameName(name), numPlayers(numPlayers), currentFrame(1) {
    // Initialization code, if any
}

Game::~Game() {
    // Cleanup code, if any
}

void Game::addPlayer(const Player& player) {
    playersMap.insert(std::make_pair(player.getName(), player));
}

void Game::startGame() {
    if (playersMap.size() < numPlayers) {
        std::cout << "Not enough players to start the game!" << std::endl;
        return;
    }
    std::cout << "Game '" << gameName << "' has started!" << std::endl;
}

void Game::nextFrame() {
    if (currentFrame <= 10) {
        currentFrame++;
        if (currentFrame < 10)
            std::cout << "Moving to frame " << currentFrame << std::endl;
    } else {
        std::cout << "Game over!" << std::endl;
        // Add any end-of-game logic if needed
    }
}

void Game::playTurn() {
    std::cout << "Round " << currentFrame << " - Enter scores for each player:" << std::endl;

    for (std::map<std::string, Player>::iterator it = playersMap.begin(); it != playersMap.end(); ++it) {
        std::string playerName = it->second.getName();
        int score, thr1, thr2;

        std::cout << "Enter score for player " << playerName << "'s first shot: ";
        std::cin >> score;

        // Basic input validation
        while (std::cin.fail() || score < 0 || score > 10) {
            std::cout << "Invalid input. Enter a valid score between 0 and 10: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> score;
        }

        // Update player scores using the setScore function for the first shot
        it->second.setScore(currentFrame, score);
        thr1 = score;
        thr2 = 0;
        // Handle strikes and spares logic (you need to implement this in Player class)
        // For now, just print a message
        if (score == 10) {
            std::cout << "Strike for " << playerName << "!" << std::endl;
        } else {
            std::cout << "Score for " << playerName << "'s first shot: " << score << std::endl;

            // Check if the player gets a second shot
            if (currentFrame < 10 && score < 10) {
                std::cout << "Enter score for " << playerName << "'s second shot: ";
                std::cin >> score;

                // Basic input validation
                while (std::cin.fail() || score < 0 || score > (10 - it->second.getScore(currentFrame))) {
                    std::cout << "Invalid input. Enter a valid score between 0 and "
                              << (10 - it->second.getScore(currentFrame)) << ": ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> score;
                }

                // Update player scores using the setScore function for the second shot
                it->second.setScore(currentFrame, score, /* secondShot = */ true);
                 if (currentFrame>1)
                    pk.sumpunt(it->second, currentFrame -1, it->second.getScore(currentFrame-2));
                pk.calc_punt(it->second, currentFrame-1, thr1, thr2);
                std::cout << "Score for " << playerName << "'s second shot: " << score << std::endl;
            }
        }
    }

    // After all players have entered their scores, you can print the results or perform additional logic.

    Printing::printScores(currentFrame, playersMap);

    sleep(2);
    system("clear");
}
