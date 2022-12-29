#include "test_shared_ptr.h"
#include <iostream>
#include <stdexcept>

Variable::Variable():my_name("unnamed")
{
    std::cout << "  Variable::" << my_name << "()\n";
}

Variable::Variable(std::string my_name)
{
    this->my_name = my_name;
    std::cout << "  Variable::" << my_name << "()\n";
}

Variable::~Variable() {
    std::cout << "  Variable::~" << my_name << "()\n";
}

BaseOne::BaseOne(int tests_num) {
    std::cout << "  -=-=-=-Test(" << tests_num << ")-=-=-=-\n";
    std::cout << "  BaseOne::BaseOne()\n";
}
    
BaseOne::~BaseOne() {
    std::cout << "  BaseOne::~BaseOne()\n";
}

BaseTwo::BaseTwo() {
    std::cout << "  BaseTwo::BaseTwo()\n";
}

BaseTwo::~BaseTwo() {
    std::cout << "  BaseTwo::~BaseTwo()\n";
}

Derived::Derived(int tests_num) : BaseOne(tests_num), BaseTwo(),
                    first_one_ptr(std::make_shared<Variable>("first_one_ptr")),
                    second_one_ptr(std::make_shared<Variable>("second_one_ptr"))
{
    std::cout << "  Derived::Derived()\n";

    switch (tests_num) {
        case 1: // ok
            break;
        case 2: // ok
            second_one_ptr->ptr = first_one_ptr;
            break;
        case 3: // first_one will be destroyed before second_one
            first_one_ptr->ptr = second_one_ptr;
            break;
        case 4: // first_one and second_one won't be destroyed
            first_one_ptr->ptr = second_one_ptr;
            second_one_ptr->ptr = first_one_ptr;
            break;
        default:
            const std::string err("invalid parameter test_num\n");
            std::cout << err;
            throw std::runtime_error(err);
    }
}

Derived::~Derived() {
    std::cout << "  Derived::~Derived()\n";
}
