//
// Created by TriD on 19.06.2022.
//

#ifndef MINESWEEPER_MINEFIELD_H
#define MINESWEEPER_MINEFIELD_H

#include "array2d.h"

class Minefield {
public:
    explicit Minefield(Array2D<Tile>&& tiles);

    [[nodiscard]] bool isEmpty(std::size_t x, std::size_t y) const;
    [[nodiscard]] bool isMine(std::size_t x, std::size_t y) const;
    [[nodiscard]] bool isNumber(std::size_t x, std::size_t y) const;

    Tile& getTile(std::size_t x, std::size_t y);
    [[nodiscard]] const Tile& getTile(std::size_t x, std::size_t y) const;

    [[nodiscard]] std::size_t getWidth() const;
    [[nodiscard]] std::size_t getHeight() const;

private:
    Array2D<Tile> _tiles;
};


#endif //MINESWEEPER_MINEFIELD_H
