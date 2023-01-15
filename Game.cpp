#include <iostream>

#include "Game.h"
#include "Shared.h"
#include "Crystal.h"
#include "Move.h"
#include "Player.h"
#include "Board.h"
#include "AI.h"

bool Game::gameEnds1(Shared &board) {
    int counter = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board.board.at(i).at(j) == 0){
                counter++;
            }
        }
    }
    return counter == 0;
}

bool Game::gameEnds2(Shared &board) {
    int counter1 = 0;
    int counter2 = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board.board.at(i).at(j) == 1){
                counter1++;
            }
            if (board.board.at(i).at(j) == 2){
                counter2++;
            }
        }
    }
    return counter1 == 0 or counter2 == 0;
}

bool Game::gameEnds3(Shared &board){
    auto counter1 = 0;
    auto counter2 = 0;
    for (auto item : Move::getPossibleMoves(board, 1)) {
        counter1++;
    }
    for (auto item : Move::getPossibleMoves(board, 1)) {
        counter2++;
    }
    return counter1 == 0 or counter2 == 0;
}



bool Game::gameEnds(Shared &board){
    return gameEnds1(board) or gameEnds2(board) or gameEnds3(board);
};

int Game::selectGameType() {
    int game_mode;
    while (true) { // infinite loop
        std::cout << '\n' << "Enter game mode, 1 for Player vs Player, 2 for Player vs AI: ";
        std::cin >> game_mode;
        std::cout << '\n';
        if (game_mode == 1 or game_mode == 2) {
            break;
        }
        else {
            std::cout << "Invalid game mode" << '\n';
        }
    }
    if (game_mode == 1) {
        return 1; // PvP
    } else if (game_mode == 2) {
        return 2; // PvAI
    }
}

void Game::gameIntro() {
    std::cout <<  '\n' << "It's popular board game called Hexxagon"<< '\n';
    std::cout << "Board size is 16x8, so as input you will use rows from 0 to 16 and columns from 0 to 8" << '\n';
    std::cout << "0 represents available space, 1 is for player1 and 2 is for player2" << '\n';
    std::cout << "If you get lost don't worry there will be some type of information which will help you" << '\n';
    std::cout << "Good luck and have fun :)" << '\n';
}

void Game::game(Shared &board){
    gameIntro();

    int type = selectGameType();
    bool currentPlayer = true; // true for P1, false for P2
    Crystal::setStartLocation(board);

    while (!gameEnds(board)){
        if (type == 1){
            if (currentPlayer){
                std::cout << "Player 1 turn " << '\n' << '\n';
                Board::printBoard(board);
                Move::movePlayer(board, 1, 2);
                currentPlayer = false;
            }
            else{
                std::cout << "Player 2 turn " << '\n' << '\n';
                Board::printBoard(board);
                Move::movePlayer(board, 2, 1);
                currentPlayer = true;
            }
        }
        if (type == 2){
            if (currentPlayer){
                std::cout << "Player 1 turn " << '\n' << '\n';
                Board::printBoard(board);
                Move::movePlayer(board, 1, 2);
                currentPlayer = false;
            }
            else {
                std::cout << "Player 2 turn " << '\n' << '\n';
                Board::printBoard(board);
                AI::moveAI(board);
                currentPlayer = true;
            }
        }
    }
    Player::whichOneWins(board);
}
