#include "game_state_builder.h"

#include <iostream>

int main() {
    auto gameState = GameStateBuilder::makeGameState(10, 10, 10);
    const auto& minefield = gameState.getMinefield();

    for (std::size_t y = 0; y < minefield.getHeight(); ++y) {
        for (std::size_t x = 0; x < minefield.getWidth(); ++x) {
            const auto& tile = minefield.getTile(x, y);
            if (tile.counter == Tile::mine) {
                std::cout << "m";
            } else {
                std::cout << tile.counter;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
