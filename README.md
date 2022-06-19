Minesweeper
===========
Part 1. Data Structures
------
Field tiles are represented as a structure Tile (see tile.h) which stores a number of adjacent bombs and whether the tile is
open or not.

To store game field was selected a std::vector of field Tiles. To simplify work with that vector, was created a template
class Array2D (see array2d.h). Class Minefield (see minefield.h/minefield.cpp) is a wrapper around an Array2d to give
helper methods to work with the field.

Part 2. Populating with bombs
-----------------------------
First, the class to store game state is needed. In that class would be stored things like game field state, play time,
scores, etc. See game_state.h.

Creating the game field is not the responsibility of the game state, so for that must be used GameStateBuilder class 
(see, game_state_builder.h/cpp). That class has one public static method that call methods from the anonymous namespace 
to generate bombs placement using standard random library.

There is also a simple method to avoid bombs colliding by moving bomb to the right (or to the next line if we are to far
to the right) while an empty tile will not be found.

