#ifndef HEXXAGON_GAME_H
#define HEXXAGON_GAME_H
#include "Shared.h"


class Game {
private:

    /***
     *
     * @param board Global board variable
     * @return true if there is no empty space
     */
    static bool gameEnds1(Shared &board);
    /***
     *
     * @param board
     * @return true if there is only one player on board
     */
    static bool gameEnds2(Shared &board);

    /***
     *
     * @param board Global board variable
     * @return true if there is no possible moves
     */
    static bool gameEnds3(Shared &board);
    /***
     *
     * @param board Global board variable
     * @return true if one of the gameEnds scenarios is true
     */
    static bool gameEnds(Shared &board);

    /***
     *
     * @return Game type, 1 Player vs Player, 2 Player vs AI
     */
    static int selectGameType();
    /***
     * @brief Quick introduction to game
     */
    static void gameIntro();
public:

    /***
     * @brief Game logic with infinite while loop (breaks when game ends)
     *
     * @param board Global board variable
     */
    static void game(Shared &board);


};


#endif //HEXXAGON_GAME_H
