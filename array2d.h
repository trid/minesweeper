//
// Created by TriD on 19.06.2022.
//

#ifndef MINESWEEPER_ARRAY2D_H
#define MINESWEEPER_ARRAY2D_H

#include <stdexcept>
#include <vector>

#include "mines.h"
#include "tile.h"


// Wrapper around std::vector to use it as 2d array
// I'd like to add Subscribe operator, but there are no multiple arguments for it, waiting for C++ 23
template <class T>
class Array2D {
public:
    Array2D(std::size_t width, std::size_t height)
            : _width(width)
            , _height(height)
    {
        _items.reserve(width * height);
    }

    T& at(std::size_t x, std::size_t y) {
        if (x >= _width) {
            throw std::out_of_range("Width is out of range");
        }
        if (y >= _height) {
            throw std::out_of_range("Height is out of range");
        }

        return _items[y * _height + x];
    }

    const T& at(std::size_t x, std::size_t y) const {
        if (x >= _width) {
            throw std::out_of_range("Width is out of range");
        }
        if (y >= _height) {
            throw std::out_of_range("Height is out of range");
        }

        return _items[y * _height + x];
    }

    [[nodiscard]] std::size_t getWidth() const {
        return _width;
    }

    [[nodiscard]] std::size_t getHeight() const {
        return _height;
    }
private:
    std::size_t _width;
    std::size_t _height;

    std::vector<T> _items;
};

#endif //MINESWEEPER_ARRAY2D_H
