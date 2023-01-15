#include "AI.h"
#include "Move.h"

bool AI::moveOneTile(Shared &board, const int &x, const int &y) {
    std::pair<int, int> cordsSmall = Move::reduceIfNotInArrayRange(x - 1, y - 1);
    std::pair<int, int> cordsBig = Move::reduceIfNotInArrayRange(x - 1, y - 1);

    if(board.board.at(cordsSmall.first).at(y) == 2){return true;}
    if(board.board.at(cordsSmall.first).at(cordsSmall.second) == 2){return true;}
    if(board.board.at(x).at(cordsSmall.second) == 2){return true;}
    if(board.board.at(cordsBig.first).at(y) == 2){return true;}
    if(board.board.at(cordsBig.first).at(cordsBig.second) == 2){return true;}
    if(board.board.at(x).at(cordsBig.second) == 2){return true;}
    else{return false;}
}


bool AI::moveTwoTiles(Shared &board, const int &x, const int &y) {

    std::pair<int, int> cordsSmall1 = Move::reduceIfNotInArrayRange(x - 1, y - 1);
    std::pair<int, int> cordsBig1 = Move::reduceIfNotInArrayRange(x + 1, y + 1);
    std::pair<int, int> cordsSmall2 = Move::reduceIfNotInArrayRange(x - 2, y - 2);
    std::pair<int, int> cordsBig2 = Move::reduceIfNotInArrayRange(x + 2, y + 2);

    if(board.board.at(cordsSmall2.first).at(y) == 2){return true;}
    if(board.board.at(cordsSmall1.first).at(cordsBig1.second) == 2){return true;}
    if(board.board.at(x).at(cordsBig2.second) == 2){return true;}
    if(board.board.at(cordsBig1.first).at(cordsBig2.second) == 2){return true;}
    if(board.board.at(cordsBig2.first).at(cordsBig2.second) == 2){return true;}
    if(board.board.at(cordsBig2.first - 2).at(cordsBig1.second) == 2){return true;}
    if(board.board.at(cordsBig2.first).at(y) == 2){return true;}
    if(board.board.at(cordsBig1.first).at(cordsSmall1.second) == 2){return true;}
    if(board.board.at(x).at(cordsSmall2.second) == 2){return true;}
    if(board.board.at(cordsSmall1.first).at(cordsSmall2.second) == 2){return true;}
    if(board.board.at(cordsSmall2.first).at(cordsSmall2.second) == 2){return true;}
    if(board.board.at(cordsSmall2.first).at(cordsSmall1.second) == 2){return true;}
    else{return false;}

}

int AI::minimax(Shared &board, const int &depth, const bool &isMaximizing) {

    if (depth == 0) {
        int score = 0;

        return score; // evaluate score of current board state
    }

    if (isMaximizing) {
        int bestScore = -1e9;
        for (int i = 0; i <= 8; i++) {
            for (int j = 0; j <= 8; j++) {
                if (board.board.at(i).at(j) == 0 and (moveOneTile(board, i, j) or moveTwoTiles(board, i, j))) {


                    board.board.at(i).at(j) = 1;
                    bestScore = std::max(bestScore, minimax(board, depth - 1, false));
                    board.board.at(i).at(j) = 0;
                }
            }
        }
        return bestScore;
    }
    else {
        int bestScore = 1e9;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board.board.at(i).at(j) == 0 and (moveOneTile(board, i, j) or moveTwoTiles(board, i, j))) {
                    board.board.at(i).at(j) = 2;
                    bestScore = std::min(bestScore, minimax(board, depth - 1, true));
                    board.board.at(i).at(j) = 0;
                }
            }
        }
        return bestScore;
    }
}

std::pair<int, int> AI::getBestMove(Shared &board, const int &depth) {
    int bestScore = -1e9;
    int bestRow, bestCol;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board.board.at(i).at(j) == 0 and (moveOneTile(board, i, j) or moveTwoTiles(board, i, j))) {

                board.board.at(i).at(j) = 1;
                int score = minimax(board, depth, false);
                board.board.at(i).at(j) = 0;

                if (score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }

    return std::make_pair(bestRow, bestCol);
}


void AI::moveAI(Shared &board){
    std::pair<int, int> moves = AI::getBestMove(board, 2);

    board.board.at(moves.first).at(moves.second) = 2;
    Move::updateNeighboringPositions(board, moves.first, moves.second, 2, 1);
    
}



