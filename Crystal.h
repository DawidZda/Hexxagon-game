#ifndef HEXXAGON_CRYSTAL_H
#define HEXXAGON_CRYSTAL_H
#include <iostream>
#include <array>
#include "Shared.h"



class Crystal {
private:
    /***
     * @brief Function that's sets location on board to player
     *
     * @param board Global variable board
     * @param xLocation X position of crystal
     * @param yLocation Y position of crystal
     * @param player Player assigned to position
     */
    static void setLocation(Shared &board, const int &xLocation, const int &yLocation, const int &player);
public:

    /***
     * @brief Function that's check for player
     *
     * @param board Global variable board
     * @param xLocation X position of crystal
     * @param yLocation Y position of crystal
     * @param player Player assigned to position
     * @return true if there is a player on location defined by xLocation and yLocation, false otherwise
     */

    static bool checkForPlayer(Shared &board, const int &xLocation, const int &yLocation, const int &player);

    /***
     * @brief Function that's sets start location of crystals on board
     *
     * @param board
     */
    static void setStartLocation(Shared &board);



};


#endif //HEXXAGON_CRYSTAL_H
