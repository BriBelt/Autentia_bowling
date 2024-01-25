#include <iostream>
#include "includes/game_hpp/game.hpp"  // Include the header file for the Game class
#include "includes/UI_hpp/ui.hpp"

int main() {
    std::string str;

	std::cout << "Welcome to our Bowling!" << std::endl;

    // Step 1: Enter the number of players
    int numPlayers;
    do {
        std::cout << "Enter the number of players (Select a number between 1 and 4): ";
        std::cin >> str;
        numPlayers = std::atoi(str.c_str());
    } while (numPlayers < 1 || numPlayers > 4);

    // Step 2: Create a Game object and add players
    Game game("Bowling", numPlayers);

    for (int i = 1; i <= numPlayers; ++i) {
        std::cout << "Enter the name for Player " << i << ": ";
        std::cin >> str;
        Player player(str, i);
        game.addPlayer(player);
    }

    // Step 3: Start the game
    game.startGame();
	game.setCurrentFrame(1);

    // Step 4: Play turns until the game is over
    while (game.getCurrentFrame() <= 10) {
		// Clean Terminal
        game.playTurn();
		// ui.displayScores(Player);
        game.nextFrame();  // Advance to the next frame10

        // Check if the game is over (for simplicity, you might want to implement a proper end condition)
        if (game.getCurrentFrame() >= 10) {
            std::cout << "Game over!" << std::endl;
			//ui.finalScores();
            break;
        }
    }

    return (0);
}
