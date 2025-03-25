#pragma once
#ifndef DSU_HPP
#define DSU_HPP

#include <vector>
#include <iterator>

class dsu {
    std::vector<ptrdiff_t> parent;
public:
    dsu(size_t n) : parent(n + 1) {
        for (size_t i = 0; i <= n; i++) parent[i] = i;
    }

    ptrdiff_t belong(ptrdiff_t x) {
        return parent[x] == x ? x : parent[x] = belong(parent[x]);
    }

    bool merge(ptrdiff_t x, ptrdiff_t y) {
        x = belong(x), y = belong(y);
        if (x == y) return false;
        if (x > y) std::swap(x, y);
        parent[x] = parent[y] = x;
        return true;
    }

    bool same(ptrdiff_t x, ptrdiff_t y) {
        return belong(x) == belong(y);
    }

    size_t count() const {
        size_t cnt = 0;
        for (size_t i = 1; i < parent.size(); i++) {
            if (parent[i] == i) cnt++;
        }
        return cnt;
    }
};

#endif // DSU_HPP