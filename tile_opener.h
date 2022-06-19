//
// Created by TriD on 19.06.2022.
//

#ifndef MINESWEEPER_TILE_OPENER_H
#define MINESWEEPER_TILE_OPENER_H

#include <cstddef>

class Minefield;

enum class OpenResult {
    Success,
    Mine
};

class TileOpener {
public:
    static OpenResult openTile(Minefield& minefield, std::size_t x, std::size_t y);
};


#endif //MINESWEEPER_TILE_OPENER_H
