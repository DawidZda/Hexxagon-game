#include "Move.h"
#include "Player.h"
#include "Board.h"
#include "Crystal.h"

bool Move::checkIfOccupied(Shared &board, const int &x, const int &y){
    return board.board.at(x).at(y) == 0;
}

std::pair<int, int> Move::reduceIfNotInArrayRange( int x, int y) {
    if (x < 0) x = 0;
    if (x > 8) x = 8;
    if (y < 0) y = 0;
    if (y > 8) y = 8;

    return {x, y};

}
bool Move::moveOneTile(const int &firstX, const int &firstY, const int &secondX, const int &secondY) {
    if (firstX - 1 == secondX and firstY == secondY){return true;}
    if (firstX - 1 == secondX and firstY - 1 == secondY){return true;}
    if (firstX == secondX and firstY - 1 == secondY){return true;}
    if (firstX + 1 == secondX and firstY == secondY){return true;}
    if (firstX + 1 == secondX and firstY + 1 == secondY){return true;}
    if (firstX == secondX and firstY + 1 == secondY){return true;}
    else{return false;}
}

bool Move::moveTwoTiles(const int &firstX, const int &firstY, const int &secondX, const int &secondY) {
    if (firstX - 2 == secondX and firstY == secondY){return true;}
    if (firstX - 1 == secondX and firstY + 1 == secondY){return true;}
    if (firstX  == secondX and firstY + 2 == secondY){return true;}
    if (firstX + 1 == secondX and firstY + 2 == secondY){return true;}
    if (firstX + 2 == secondX and firstY + 1 == secondY){return true;}
    if (firstX + 2 == secondX and firstY == secondY){return true;}
    if (firstX + 1 == secondX and firstY - 1 == secondY){return true;}
    if (firstX + 2 == secondX and firstY + 2 == secondY){return true;}
    if (firstX == secondX and firstY - 2 == secondY){return true;}
    if (firstX - 1 == secondX and firstY - 2 == secondY){return true;}
    if (firstX - 2 == secondX and firstY - 2 == secondY){return true;}
    if (firstX - 2 == secondX and firstY - 1 == secondY){return true;}
    else{return false;}
}

bool Move::ifMoveByOnePossible(Shared &board, int inputFirst, int inputSecond, int input2First, int input2Second, const int &player) {
    return moveOneTile(inputFirst, inputSecond, input2First, input2Second) and checkIfOccupied(board, input2First, input2Second)
           and Crystal::checkForPlayer(board, inputFirst, inputSecond, player);
}

bool Move::ifMoveByTwoPossible(Shared &board, int inputFirst,  int inputSecond, int input2First, int input2Second, const int &player) {
    return moveTwoTiles(inputFirst, inputSecond, input2First, input2Second) and checkIfOccupied(board, input2First, input2Second)
           and Crystal::checkForPlayer(board, inputFirst, inputSecond, player);
}

void Move::updateNeighboringPositions(Shared &board, const int &x, const int &y, const int &player, const int &player2) {
    std::pair<int, int> cordsSmall = reduceIfNotInArrayRange(x - 1, y - 1);
    std::pair<int, int> cordsBig = reduceIfNotInArrayRange(x + 1, y + 1);

    if (board.board.at(cordsSmall.first).at(y) == player2){board.board.at(cordsSmall.first).at(y) = player;}
    if (board.board.at(cordsSmall.first).at(cordsSmall.second) == player2){board.board.at(cordsSmall.first).at(cordsSmall.second) = player;}
    if (board.board.at(x).at(cordsSmall.second) == player2){board.board.at(x).at(cordsSmall.second) = player;}
    if (board.board.at(cordsBig.first).at(y) == player2){board.board.at(cordsBig.first).at(y) = player;}
    if (board.board.at(cordsBig.first).at(cordsBig.second) == player2){board.board.at(cordsBig.first).at(y + 1) = player;}
    if (board.board.at(x).at(cordsBig.second) == player2){board.board.at(x).at(cordsBig.second) = player;}

}

std::vector<std::pair<int, int>> Move::getPossibleMoves(Shared &board, const int &player){
    std::vector<std::pair<int, int>> moves;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board.board.at(i).at(j) == player){
                for (int k = 0; k < 9; ++k) {
                    for (int l = 0; l < 9; ++l) {
                        if (ifMoveByOnePossible(board, i, j, k, l, player)){
                            moves.emplace_back(k, l);
                        }
                        if (ifMoveByTwoPossible(board, i, j, k, l, player)){
                            moves.emplace_back(k, l);
                        }
                    }
                }
            }
        }
    }
    return moves;
}

void Move::movePlayer(Shared &board, const int &player, const int &player2){
    int xLocation, yLocation, xLocation2, yLocation2;

    while(true){
        //Board::printBoard(board);
        std::cout << '\n' << "Firstly, select with which crystal you want to move: " << '\n';
        while(true){
            std::cout << '\n' << "Select a row from 0 to 16: ";
            std::cin >> xLocation;
            std::cout << '\n' << "Select a column from 0 to 8: ";
            std::cin >> yLocation;
            std::pair<int, int> inputToCheck = Player::transformPlayerInput(xLocation, yLocation);
            if (Crystal::checkForPlayer(board, inputToCheck.first, inputToCheck.second, player)){
                break;
            }
            else{
                std::cout << "Use your crystal to move" << '\n';
            }
        }
        const std::pair<int, int> &input = Player::transformPlayerInput(xLocation, yLocation);
        while(true){
            std::cout <<  '\n' <<"Secondly, select on which hex you want to move: " << '\n';
            std::cout << '\n' << "Select a row from 0 to 16: ";
            std::cin >> xLocation2;
            std::cout << '\n' << "Select a column from 0 to 8: ";
            std::cin >> yLocation2;
            std::pair<int, int> inputToCheck2 = Player::transformPlayerInput(xLocation2, yLocation2);
            if (Crystal::checkForPlayer(board, inputToCheck2.first, inputToCheck2.second, player) or Crystal::checkForPlayer(board, inputToCheck2.first, inputToCheck2.second, player2)){
                std::cout << "You can't move on an occupied hex!" << '\n';
            }
            if (Crystal::checkForPlayer(board, inputToCheck2.first, inputToCheck2.second, 3)){
                std::cout << "This isn't a board!" << '\n';
            }
            if (not moveOneTile(input.first, input.second, inputToCheck2.first, inputToCheck2.second) and not moveTwoTiles(input.first, input.second, inputToCheck2.first, inputToCheck2.second)){
                std::cout << "You can't move here, it's not in your range!" << '\n';
            }
            else{
                break;
            }
        }
        const std::pair<int, int> &input2 = Player::transformPlayerInput(xLocation2, yLocation2);

        if (ifMoveByOnePossible(board, input.first, input.second, input2.first, input2.second, player)){
            board.board.at(input2.first).at(input2.second) = player;
            updateNeighboringPositions(board, input2.first, input2.second, player, player2);

            Player::countCurrentPoints(board);
            break;
        }
        if (ifMoveByTwoPossible(board, input.first, input.second, input2.first, input2.second, player)){
            board.board.at(input2.first).at(input2.second) = player;
            board.board.at(input.first).at(input.second) = 0;
            updateNeighboringPositions(board, input2.first, input2.second, player, player2);

            Player::countCurrentPoints(board);
            break;
        }
    }
}
