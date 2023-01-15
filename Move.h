//
// Created by Dawid Zdanowicz on 19/12/2022.
//

#ifndef HEXXAGON_MOVE_H
#define HEXXAGON_MOVE_H
#include <iostream>
#include <vector>
#include "Shared.h"

class Move {
private:
    /***
     *
     * @param board Global variable board
     * @param x X location
     * @param y Y location
     * @return true if there is empty space at x,y location
     */
    static bool checkIfOccupied(Shared &board, const int &x, const int &y);

    /***
     * @brief Bool that's check if crystal is in range to move on given location
     *
     * @param firstX Current X location
     * @param firstY Current Y location
     * @param secondX Destined X location
     * @param secondY Destined Y location
     * @return true if crystal is in range to be moved by one tile
     */
    static bool moveOneTile(const int &firstX, const int &firstY, const int &secondX, const int &secondY);

    /***
     * @brief Bool that's check if crystal is in range to move on given location
     *
     * @param firstX Current X location
     * @param firstY Current Y location
     * @param secondX Destined X location
     * @param secondY Destined Y location
     * @return true if crystal is in range to be moved by two tiles
     */
    static bool moveTwoTiles(const int &firstX, const int &firstY, const int &secondX, const int &secondY);

    /***
     *
     * Function that's takes all conditions to successfully move a player by one tile
     *
     * @param board Global variable board
     * @param inputFirst Current X location
     * @param inputSecond Current Y location
     * @param input2First Destined X location
     * @param input2Second Destined Y location
     * @param player Current player
     * @return true if it's possible to move
     */
    static bool ifMoveByOnePossible(Shared &board, int inputFirst, int inputSecond, int input2First, int input2Second, const int &player);

    /***
     *
     * Function that's takes all conditions to successfully move a player by two tiles
     *
     * @param board Global variable board
     * @param inputFirst Current X location
     * @param inputSecond Current Y location
     * @param input2First Destined X location
     * @param input2Second Destined Y location
     * @param player Current player
     * @return true if it's possible to move
     */
    static bool ifMoveByTwoPossible(Shared &board, int inputFirst,  int inputSecond, int input2First, int input2Second, const int &player);
public:

    /***
     * @brief If input is out of array range, this function will fix it
     *
     * @param x X location on board
     * @param y Y location on board
     * @return Fixed x,y locations
     */
    static std::pair<int, int> reduceIfNotInArrayRange(int x, int y);

    /***
     *
     * Takes care of updating neighboring positions, especially for capturing enemy crystals
     *
     * @param board Global variable board
     * @param x X Location on board
     * @param y Y Location on board
     * @param player Current player
     * @param player2 Enemy player
     */
    static void updateNeighboringPositions(Shared &board, const int &x, const int &y, const int &player, const int &player2);

    /***
     * @brief Checking for all possible moves
     *
     * @param board Global board variable
     * @param player Current player
     * @return Returns vector of pair with all possible moves combination
     */
    static std::vector<std::pair<int,int>> getPossibleMoves(Shared &board, const int &player);

    /***
     * @brief Responsible for moving player
     *
     * This function provide moving player by taking input of current crystal cords,
     * then taking input of desire move destination.
     * If everything is correct move logic will be implemented (with duplicating and capturing enemy crystals)
     *
     * @param board Global variable board
     * @param player Current player
     * @param player2 Current enemy player
     */
    static void movePlayer(Shared &board, const int &player, const int &player2);


};


#endif //HEXXAGON_MOVE_H
