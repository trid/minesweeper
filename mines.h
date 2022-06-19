//
// Created by TriD on 19.06.2022.
//

#ifndef MINESWEEPER_MINES_H
#define MINESWEEPER_MINES_H

#include <utility>
#include <unordered_set>

// A bad example of the pair hash, ok for demonstration purpose. In the real life, I'd better use boost::hash
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        return h1 ^ h2;
    }
};


using Mines = std::unordered_set<std::pair<std::size_t, std::size_t>, pair_hash>;

#endif //MINESWEEPER_MINES_H
