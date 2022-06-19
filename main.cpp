#include <iostream>
#include <sstream>

#include "game_state_builder.h"
#include "tile_opener.h"

void printField(const Minefield& minefield) {
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
}

void printWithFogOfWar(const Minefield& minefield) {
    for (std::size_t y = 0; y < minefield.getHeight(); ++y) {
        for (std::size_t x = 0; x < minefield.getWidth(); ++x) {
            const auto& tile = minefield.getTile(x, y);
            if (!tile.isOpen) {
                std::cout << "?";
                continue;
            }

            if (tile.counter == Tile::mine) {
                std::cout << "m";
                continue;
            }

            std::cout << tile.counter;
        }
        std::cout << std::endl;
    }
}

int main() {
    auto gameState = GameStateBuilder::makeGameState(10, 10, 10);
    auto& minefield = gameState.getMinefield();

    printField(minefield);

    while (true) {
        std::string command;
        std::getline(std::cin, command);
        if (command == "q") {
            break;
        }

        std::stringstream ss(command);
        std::size_t x, y;
        ss >> x;
        ss >> y;

        auto result = TileOpener::openTile(minefield, x, y);
        printWithFogOfWar(minefield);

        if (result == OpenResult::Mine) {
            std::cout << "Btoooom!!!" << std::endl;
            break;
        }
    }

    return 0;
}
