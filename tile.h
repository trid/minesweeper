//
// Created by TriD on 19.06.2022.
//

#ifndef MINESWEEPER_TILE_H
#define MINESWEEPER_TILE_H

// Bit field can be used for a slight improvement of memory footprint
struct Tile {
public:
    static constexpr unsigned int empty = 0;
    static constexpr unsigned int mine = 9;

public:
    bool isOpen = false;
    unsigned int counter = 0;
};

#endif //MINESWEEPER_TILE_H
