//
// Created by TriD on 19.06.2022.
//

#include "game_state.h"

GameState::GameState(unsigned int minesCount, Minefield&& minefield)
    : _minefield(minefield)
{}

const Minefield& GameState::getMinefield() const {
    return _minefield;
}
