#include "Crystal.h"
#include "Shared.h"

void Crystal::setLocation(Shared &board, const int &xLocation, const int &yLocation, const int &player) {
   board.board.at(xLocation).at(yLocation) = player;
}

bool Crystal::checkForPlayer(Shared &board, const int &xLocation, const int &yLocation, const int &player) {
    return board.board.at(xLocation).at(yLocation) == player;
}

void Crystal::setStartLocation(Shared &board){

    // Setting location for player 1
    setLocation(board,8, 4, 1);
    setLocation(board,0, 0, 1);
    setLocation(board,4, 8, 1);

    // Setting location for player 2
    setLocation(board,0, 4, 2);
    setLocation(board,4, 0, 2);
    setLocation(board,8, 8, 2);
}