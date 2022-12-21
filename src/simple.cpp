//
// Created by devdistress on 12/21/22.
//
#include "simple.h"
#include<iostream>

Simple::MyType Simple::ls = Simple::MyType({1, 2, 3, 4, 5});

Simple::MyType Simple::justPrint() {
    for (const auto i : ls) {
        std::cout << i << std::endl;
    }

    return ls;
}