//
// Created by devdistress on 12/28/22.
//
#pragma once

#include <iostream>
#include <tuple>

struct TestVariadicTemplate {

    template<typename... Args>
    static void printImpl(const Args &... tupleArgs) {
        size_t index = 0;
        auto printElem = [&index](const auto &x) {
            if (index++ > 0)
                std::cout << ", ";
            std::cout << x;
        };

        (printElem(tupleArgs), ...);
    }

    template<typename... Args>
    static void printTupleApplyFn(const std::tuple<Args...> &tp) {
        std::cout << "(";
        std::apply(printImpl<Args...>, tp); // <<
        std::cout << ")";
    }

    template <typename TupleT, typename Fn>
    static void for_each_tuple(TupleT&& tp, Fn&& fn, bool&& for_each = true) {
        std::apply
                (
                    [&fn, for_each](auto&& ...args)
                    {
                        if(for_each)
                            (fn(std::forward<decltype(args)>(args)), ...);
                        else
                            fn(std::forward<decltype(args)>(args)...);
                    }, std::forward<TupleT>(tp)
                );
    }

    template <typename TupleT>
    static void run(TupleT&& tp) {
        std::cout << "\n1)-=-=-=-=-=-" << std::endl;

        printTupleApplyFn(tp);

        auto helpFunc = [](const auto& first, const auto&... restArgs){
            auto printElem = [](const auto& x) {
                std::cout << ", " << x;
            };
            std::cout << "(" << first;
            (printElem(restArgs), ...);
            std::cout << ")";
        };

        std::cout << "\n2)-=-=-=-=-=-" << std::endl;
        for_each_tuple(tp, helpFunc);

        std::cout << "\n3)-=-=-=-=-=-" << std::endl;
        for_each_tuple(tp, helpFunc, false);
    }
};