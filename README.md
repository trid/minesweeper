Minesweeper
===========
Part 1. Data Structures
------
Field tiles are represented as a structure Tile (see tile.h) which stores a number of adjacent bombs and whether the tile is
open or not.

To store game field was selected a std::vector of field Tiles. To simplify work with that vector, was created a template
class Array2d (see array2d.h). Class Minefield (see minefield.h/minefield.cpp) is a wrapper around an Array2d to give
helper methods to work with the field.