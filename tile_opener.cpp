//
// Created by TriD on 19.06.2022.
//

#include "tile_opener.h"

#include <limits>

#include "minefield.h"

namespace {

void addEmptyTiles(TileCoordinates& mines, std::size_t x, std::size_t y, Minefield& minefield, std::size_t width,
                   std::size_t height) {
    if (x == std::numeric_limits<std::size_t>::max() || x >= width) {
        return;
    }
    if (y == std::numeric_limits<std::size_t>::max() || y >= height) {
        return;
    }

    auto& tile = minefield.getTile(x, y);
    if (!tile.isOpen && minefield.isEmpty(x, y)) {
        mines.insert({x, y});
    }
    tile.isOpen = true;
}

void openTilesBreathFirst(Minefield& minefield, std::size_t x, std::size_t y) {
    TileCoordinates tiles;
    tiles.insert({x, y});

    while (!tiles.empty()) {
        auto minePlace = *tiles.begin();
        addEmptyTiles(tiles, minePlace.first - 1, minePlace.second, minefield, minefield.getWidth(),
                      minefield.getHeight());
        addEmptyTiles(tiles, minePlace.first - 1, minePlace.second - 1, minefield, minefield.getWidth(),
                      minefield.getHeight());
        addEmptyTiles(tiles, minePlace.first, minePlace.second - 1, minefield, minefield.getWidth(),
                      minefield.getHeight());
        addEmptyTiles(tiles, minePlace.first + 1, minePlace.second - 1, minefield, minefield.getWidth(),
                      minefield.getHeight());
        addEmptyTiles(tiles, minePlace.first + 1, minePlace.second, minefield, minefield.getWidth(),
                      minefield.getHeight());
        addEmptyTiles(tiles, minePlace.first + 1, minePlace.second + 1, minefield, minefield.getWidth(),
                      minefield.getHeight());
        addEmptyTiles(tiles, minePlace.first, minePlace.second + 1, minefield, minefield.getWidth(),
                      minefield.getHeight());
        addEmptyTiles(tiles, minePlace.first - 1, minePlace.second + 1, minefield, minefield.getWidth(),
                      minefield.getHeight());
        tiles.erase(minePlace);
    }
}
}

OpenResult TileOpener::openTile(Minefield& minefield, std::size_t x, std::size_t y) {
    minefield.getTile(x, y).isOpen = true;

    if (minefield.isMine(x, y)) {
        return OpenResult::Mine;
    }

    if (minefield.isEmpty(x, y)) {
        openTilesBreathFirst(minefield, x, y);
    }

    return OpenResult::Success;
}
