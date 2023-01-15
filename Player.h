#ifndef HEXXAGON_PLAYER_H
#define HEXXAGON_PLAYER_H
#include <iostream>

class Player {
public:
    /***
     * Takes player input, for example row = 16 / column = 18,
     * and transform it to board acceptable format
     *
     * @param x X location of crystal
     * @param y Y location of crystal
     * @return parameters of 2D 9x9 array
     */
    static std::pair<int, int> transformPlayerInput(const int &x, const int &y);

    /***
     * @brief Iterate through whole board to keep track of current points state
     *
     * Sums up all 1 as well as 2 and adding them to dedicated player
     * @param board Global variable board
     */
    static void countCurrentPoints(Shared &board);

    /***
     * @brief Initialized at the end of the game to inform which player wins
     *
     * Checking every "hex" on board,
     * player with greater amount of points wins
     *
     * @param board Global variable board
     */
    static void whichOneWins(Shared &board);
};


#endif //HEXXAGON_PLAYER_H
