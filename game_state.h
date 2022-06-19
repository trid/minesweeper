//
// Created by TriD on 19.06.2022.
//

#ifndef MINESWEEPER_GAME_STATE_H
#define MINESWEEPER_GAME_STATE_H


#include "minefield.h"

// Stores, well, game state. Parameters like field state, received points, etc. are to be stored here
class GameState {
public:
    explicit GameState(unsigned int minesCount, Minefield&& minefield);

    [[nodiscard]] const Minefield& getMinefield() const;
    [[nodiscard]] Minefield& getMinefield();

private:
    Minefield _minefield;
};


#endif //MINESWEEPER_GAME_STATE_H
