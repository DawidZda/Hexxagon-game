#ifndef HEXXAGON_SHARED_H
#define HEXXAGON_SHARED_H
#include <iostream>
#include <array>

class Shared {
private:
    static const int SIZE = 9;
public:
    /***
     * @param board 2D 9x9 array, core of whole game, most of the time if some
     * change is happening in game, this variable is modified
     */
    std::array<std::array<int, SIZE>, SIZE> board{};


};

#endif //HEXXAGON_SHARED_H
