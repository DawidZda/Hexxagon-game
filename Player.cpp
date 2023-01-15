#include <iostream>
#include "Shared.h"
#include "Player.h"

std::pair<int, int> Player::transformPlayerInput(const int &x, const int &y) {
    if(x == 0 and y == 4){return {x, y};}

    if (x == 1 and y == 3){return {0, y};}
    if (x == 1 and y == 5){return {1, y};}

    if (x == 2 and y == 2){return {0, y};}
    if (x == 2 and y == 4){return {1, y};}
    if (x == 2 and y == 6){return {2, y};}

    if (x == 3 and y == 1){return {0, y};}
    if (x == 3 and y == 3){return {1, y};}
    if (x == 3 and y == 5){return {2, y};}
    if (x == 3 and y == 7){return {3, y};}

    if (x == 4 and y == 0){return {0, y};}
    if (x == 4 and y == 2){return {1, y};}
    if (x == 4 and y == 4){return {2, y};}
    if (x == 4 and y == 6){return {3, y};}
    if (x == 4 and y == 8){return {4, y};}

    if (x == 5 and y == 1){return {1, y};}
    if (x == 5 and y == 3){return {2, y};}
    if (x == 5 and y == 5){return {3, y};}
    if (x == 5 and y == 7){return {4, y};}

    if (x == 6 and y == 0){return {1, y};}
    if (x == 6 and y == 2){return {2, y};}
    if (x == 6 and y == 4){return {0, 7};} // X
    if (x == 6 and y == 6){return {4, y};}
    if (x == 6 and y == 8){return {5, y};}

    if (x == 7 and y == 1){return {2, y};}
    if (x == 7 and y == 3){return {3, y};}
    if (x == 7 and y == 5){return {4, y};}
    if (x == 7 and y == 7){return {5, y};}

    if (x == 8 and y == 0){return {2, y};}
    if (x == 8 and y == 2){return {3, y};}
    if (x == 8 and y == 4){return {4, y};}
    if (x == 8 and y == 6){return {5, y};}
    if (x == 8 and y == 8){return {6, y};}

    if (x == 9 and y == 1){return {3, y};}
    if (x == 9 and y == 3){return {0, 7};} // X
    if (x == 9 and y == 5){return {0, 7};} // X
    if (x == 9 and y == 7){return {6, y};}

    if (x == 10 and y == 0){return {3, y};}
    if (x == 10 and y == 2){return {4, y};}
    if (x == 10 and y == 4){return {5, y};}
    if (x == 10 and y == 6){return {6, y};}
    if (x == 10 and y == 8){return {7, y};}

    if (x == 11 and y == 1){return {4, y};}
    if (x == 11 and y == 3){return {5, y};}
    if (x == 11 and y == 5){return {6, y};}
    if (x == 11 and y == 7){return {7, y};}

    if (x == 12 and y == 0){return {4, y};}
    if (x == 12 and y == 2){return {5, y};}
    if (x == 12 and y == 4){return {6, y};}
    if (x == 12 and y == 6){return {7, y};}
    if (x == 12 and y == 8){return {8, y};}

    if (x == 13 and y == 1){return {5, y};}
    if (x == 13 and y == 3){return {6, y};}
    if (x == 13 and y == 5){return {7, y};}
    if (x == 13 and y == 7){return {8, y};}

    if (x == 14 and y == 2){return {6, y};}
    if (x == 14 and y == 4){return {7, y};}
    if (x == 14 and y == 6){return {8, y};}

    if (x == 15 and y == 3){return {7, y};}
    if (x == 15 and y == 5){return {8, y};}

    if(x == 16 and y == 4){return {8, y};}

    else{
        return {0, 7}; // return "nothing"
    }

}

void Player::countCurrentPoints(Shared &board){
    int player1 = 0;
    int player2 = 0;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board.board.at(i).at(j) == 1){
                player1++;
            }
            if (board.board.at(i).at(j) == 2){
                player2++;
            }
        }
    }
    std::cout << '\n' << "Player 1 points: " << player1 << '\n';
    std::cout << "Player 2 points: " << player2 << '\n' << '\n';
}

void Player::whichOneWins(Shared &board) {
    int player1 = 0;
    int player2 = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board.board.at(i).at(j) == 1){
                player1++;
            }
            if (board.board.at(i).at(j) == 2){
                player2++;
            }
        }
    }
    if (player1 > player2){
        std::cout << "Player 1 won!" << '\n';
    }
    if (player1 < player2){
        std::cout << "Player 2 won!" << '\n';
    }
    if (player1 == player2){
        std::cout << "It's draw!" << '\n';
    }
}