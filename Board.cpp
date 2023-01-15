#include "Board.h"

void Board::makeHexGrid(Shared &board) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if ((i == 0 and j > 4) or (i == 8 and j < 4)){
                board.board.at(i).at(j) = 3;
            }
            if ((i == 1 and j > 5) or (i == 7 and j < 3)){
                board.board.at(i).at(j) = 3;
            }
            if ((i == 2 and j > 6) or (i == 6 and j < 2)){
                board.board.at(i).at(j) = 3;
            }
            if ((i == 3 and j > 7) or (i == 5 and j < 1)){
                board.board.at(i).at(j) = 3;
            }
            if ((i == 3 and j == 4) or (i == 4 and j == 3) or (i == 5 and j == 5)){
                board.board.at(i).at(j) = 3;
            }
        }
    }
}

 void Board::printBoard(Shared &board) {
    makeHexGrid(board);
    board.board.at(0).at(7) = 3;
    std::cout << "      ";
     for (int i = 0; i < 9; ++i) {
         std::cout << i << " ";
     }
    std::cout << '\n' << '\n';
    std::cout << "0" << "     "<<"        " << board.board.at(0).at(4) << "        " << '\n';
    std::cout << "1" << "     "<<"      " << board.board.at(0).at(3) << "   " << board.board.at(1).at(5) << "      " << '\n';
    std::cout << "2" << "     "<<"    " << board.board.at(0).at(2) << "   " << board.board.at(1).at(4) << "   " << board.board.at(2).at(6) << "    " << '\n';
    std::cout << "3" << "     "<<"  " << board.board.at(0).at(1) << "   " << board.board.at(1).at(3) << "   " << board.board.at(2).at(5) << "   " << board.board.at(3).at(7) << "   " << '\n';
    std::cout << "4" << "     "<<board.board.at(0).at(0) << "   " << board.board.at(1).at(2) << "   " << board.board.at(2).at(4) << "   " << board.board.at(3).at(6) << "   " << board.board.at(4).at(8) << '\n';
    std::cout << "5" << "     "<<"  " << board.board.at(1).at(1) << "   " << board.board.at(2).at(3) << "   " << board.board.at(3).at(5) << "   " << board.board.at(4).at(7) << "   " << '\n';
    std::cout << "6" << "     "<<board.board.at(1).at(0) << "   " << board.board.at(2).at(2) << "   " << "X" << "   " << board.board.at(4).at(6) << "   " << board.board.at(5).at(8) << '\n';
    std::cout << "7" << "     "<<"  " << board.board.at(2).at(1) << "   " << board.board.at(3).at(3) << "   " << board.board.at(4).at(5) << "   " << board.board.at(5).at(7) << "   " << '\n';
    std::cout << "8" << "     "<<board.board.at(2).at(0) << "   " << board.board.at(3).at(2) << "   " << board.board.at(4).at(4) << "   " << board.board.at(5).at(6) << "   " << board.board.at(6).at(8) << '\n';
    std::cout << "9" << "     "<<"  " << board.board.at(3).at(1) << "   " << "X" << "   " << "X" << "   " << board.board.at(6).at(7) << "   " << '\n';
    std::cout << "10" << "    "<<board.board.at(3).at(0) << "   " << board.board.at(4).at(2) << "   " << board.board.at(5).at(4) << "   " << board.board.at(6).at(6) << "   " << board.board.at(7).at(8) << '\n';
    std::cout << "11" << "    "<<"  " << board.board.at(4).at(1) << "   " << board.board.at(5).at(3) << "   " << board.board.at(6).at(5) << "   " << board.board.at(7).at(7) << "   " << '\n';
    std::cout << "12" << "    "<<board.board.at(4).at(0) << "   " << board.board.at(5).at(2) << "   " << board.board.at(6).at(4) << "   " << board.board.at(7).at(6) << "   " << board.board.at(8).at(8) << '\n';
    std::cout << "13" << "    "<<"  " << board.board.at(5).at(1) << "   " << board.board.at(6).at(3) << "   " << board.board.at(7).at(5) << "   " << board.board.at(8).at(7) << "   " << '\n';
    std::cout << "14" << "    "<<"    " << board.board.at(6).at(2) << "   " << board.board.at(7).at(4) << "   " << board.board.at(8).at(6) << "    " << '\n';
    std::cout << "15" << "    "<<"      " << board.board.at(7).at(3) << "   " << board.board.at(8).at(5) << "      " << '\n';
    std::cout << "16" << "    "<<"        " << board.board.at(8).at(4) << "        " << '\n';
}
