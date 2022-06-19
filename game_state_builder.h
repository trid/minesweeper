//
// Created by TriD on 19.06.2022.
//

#ifndef MINESWEEPER_GAME_STATE_BUILDER_H
#define MINESWEEPER_GAME_STATE_BUILDER_H

#include "game_state.h"

class GameStateBuilder {
public:
    static GameState makeGameState(std::size_t width, std::size_t height, unsigned int minesNumber);
};


#endif //MINESWEEPER_GAME_STATE_BUILDER_H
