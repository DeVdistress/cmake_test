//
// Created by devdistress on 12/21/22.
//
#include <list>

#pragma once
struct Simple {
        using MyType = std::list<int>;

    private:
        static MyType ls;

    public:
        Simple() = default;
        ~Simple() =default;

        static MyType justPrint();
};

