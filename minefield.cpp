//
// Created by TriD on 19.06.2022.
//

#include "minefield.h"

Minefield::Minefield(Array2D<Tile>&& tiles)
    : _tiles(std::move(tiles))
{}

bool Minefield::isEmpty(std::size_t x, std::size_t y) const {
    return _tiles.at(x, y).counter == Tile::empty;
}

bool Minefield::isMine(std::size_t x, std::size_t y) const {
    return _tiles.at(x, y).counter == Tile::mine;
}

bool Minefield::isNumber(std::size_t x, std::size_t y) const {
    const Tile& tile = _tiles.at(x, y);
    return tile.counter > Tile::empty && tile.counter < Tile::mine;
}

Tile& Minefield::getTile(std::size_t x, std::size_t y) {
    return _tiles.at(x, y);
}

const Tile& Minefield::getTile(std::size_t x, std::size_t y) const {
    return _tiles.at(x, y);
}

std::size_t Minefield::getWidth() const {
    return _tiles.getWidth();
}

std::size_t Minefield::getHeight() const {
    return _tiles.getHeight();
}
