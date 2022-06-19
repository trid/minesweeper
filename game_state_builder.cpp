//
// Created by TriD on 19.06.2022.
//

#include "game_state_builder.h"

#include <random>

#include "mines.h"

// In real life I'd prefer not to put some the functions from that namespace into anonymous namespace to make them
// testable, as those are more than simple helper functions, but for now it is ok-ish
namespace {
    void emplaceMine(TileCoordinates& mines, std::pair<std::size_t, std::size_t> coords, std::size_t width, std::size_t height) {
        auto maybeNewCoords = coords;
        // Checking for collisions, ugly way
        while (mines.contains(maybeNewCoords)) {
            auto newX = maybeNewCoords.first;
            auto newY = maybeNewCoords.second;

            if (coords.first < width - 1) {
                ++newX;
            } else {
                newX = 0;
                ++newY;
                // For a case when y is bigger than height
                newY = newY % height;
            }
            maybeNewCoords = std::make_pair(newX, newY);
        }
        mines.insert(maybeNewCoords);
    }

    TileCoordinates generateMinesPosition(std::size_t width, std::size_t height, unsigned int minesNumber) {
        std::random_device randomDevice;
        std::default_random_engine randomEngine(randomDevice());
        std::uniform_int_distribution<std::size_t> widthDistribution(0, width - 1);
        std::uniform_int_distribution<std::size_t> heightDistribution(0, height - 1);

        TileCoordinates result;

        for (int i = 0; i < minesNumber; i++) {
            auto x = widthDistribution(randomEngine);
            auto y = heightDistribution(randomEngine);

            // Trying to avoid collisions here
            auto coords = std::make_pair(x, y);
            emplaceMine(result, coords, width, height);
        }

        return result;
    }

    void updateTile(Array2D<Tile>& array2D, size_t x, size_t y) {
        // Standard implies that in case of integer overflow we will have maximal value for UNSIGNED types
        // for signed types, it's still UB
        if (x == std::numeric_limits<std::size_t>::max() || x >= array2D.getWidth()) {
            return;
        }
        if (y == std::numeric_limits<std::size_t>::max() || y >= array2D.getHeight()) {
            return;
        }

        auto& tile = array2D.at(x, y);
        if (tile.counter == Tile::mine) {
            return;
        }

        ++tile.counter;
    }

    void updateAdjacentTiles(Array2D<Tile>& tiles, std::size_t x, std::size_t y) {
        updateTile(tiles, x - 1, y);
        updateTile(tiles, x - 1, y - 1);
        updateTile(tiles, x, y - 1);
        updateTile(tiles, x + 1, y - 1);
        updateTile(tiles, x + 1, y);
        updateTile(tiles, x + 1, y + 1);
        updateTile(tiles, x, y + 1);
        updateTile(tiles, x - 1, y + 1);
    }

    Minefield makeMineField(std::size_t width, std::size_t height, const TileCoordinates& mines) {
        Array2D<Tile> tiles(width, height);

        for (auto item: mines) {
            tiles.at(item.first, item.second).counter = Tile::mine;
            updateAdjacentTiles(tiles, item.first, item.second);
        }

        return Minefield(std::move(tiles));
    }
}

GameState GameStateBuilder::makeGameState(std::size_t width, std::size_t height, unsigned int minesNumber) {
    if (minesNumber > width * height) {
        throw std::logic_error("Impossible to place all bombs!");
    }

    auto mines = generateMinesPosition(width, height, minesNumber);
    auto minefield = makeMineField(width, height, mines);

    return GameState(minesNumber, std::move(minefield));
}
