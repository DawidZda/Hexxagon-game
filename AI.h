#ifndef HEXXAGON_AI_H
#define HEXXAGON_AI_H
#include "Shared.h"

class AI {
private:
    /***
     * @brief Checks if it's possible to move by one tile
     *
     * @param board Global variable board
     * @param x X location on board
     * @param y Y location on board
     * @return true if it's possible to move by one tile
     */
    static bool moveOneTile(Shared &board, const int &x, const int &y);
    /***
     * @brief Checks if it's possible to move by two tiles
     *
     * @param board Global variable board
     * @param x X location on board
     * @param y Y location on board
     * @return true if it's possible to move by two tiles
     */
    static bool moveTwoTiles(Shared &board, const int &x, const int &y);

    /***
     * @brief Minimax function to recursively get best possible moves
     *
     * @param board Global variable board
     * @param depth depth of minimax algorithm
     * @param isMaximizing bool to check stage
     * @return Best possible move
     */
    static int minimax(Shared &board, const int &depth, const bool &isMaximizing);
    /***
     * @brief Get best move from available possibilities
     *
     * @param board Global variable board
     * @param depth depth of minmax algorithm
     * @return Cords of best move
     */
    static std::pair<int, int> getBestMove(Shared &board, const int &depth);

public:

    /***
     * @brief Implement AI move
     * @param board Gloabal board variable
     */
    static void moveAI(Shared &board);
};


#endif //HEXXAGON_AI_H
