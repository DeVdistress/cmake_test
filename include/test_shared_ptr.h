#pragma once

#include <memory>
#include <string>

struct Variable
{
    std::shared_ptr<Variable> ptr;
    std::string my_name;

    Variable();
    Variable(std::string my_name);
    ~Variable();
};

struct BaseOne
{
    BaseOne(int tests_num);
    // Note: non-virtual destructor is OK here
    ~BaseOne();
};

struct BaseTwo
{
    BaseTwo();
    ~BaseTwo();
};

struct Derived : public BaseOne, BaseTwo
{
    std::shared_ptr<Variable> first_one_ptr;
    std::shared_ptr<Variable> second_one_ptr;

    Derived(int tests_num);
    ~Derived();
};