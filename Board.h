#ifndef HEXXAGON_BOARD_H
#define HEXXAGON_BOARD_H
#include "Shared.h"

class Board {
private:
    /***
     * @brief Function that's make hexagonal grid
     *
     * @param board Global variable board
     */
    static void makeHexGrid(Shared &board);
public:
    /***
     * @brief Printing hexagonal board to console, also add row/column navigation
     *
     * @param board Global variable board
     */
    static void printBoard(Shared &board);

};

#endif //HEXXAGON_BOARD_H
