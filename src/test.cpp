#include "test_shared_ptr.h"
#include "test_variadic_templates.h"
#include "test_move_semantics.h"
#include "test_forward_iterator.h"

int main() {
    int res = 0;
#if(0)  //test linking of c++abi"
        std::cout << std::boolalpha << true << "\n";
#endif
#if(0)  //test shared_ptr
        // Please see   https://stackoverflow.com/questions/2254263/order-of-member-constructor-and-destructor-calls
        //              https://habr.com/ru/post/191018/ 
        {
            int test_num = 1;
            // this works well
            {
                Derived instance(test_num++);
            }

            // this works well
            {
                Derived instance(test_num++);
            }

            // first_one will be destroyed before second_one 
            {
                Derived instance(test_num++);
            }

            // first_one and second_one won't be destroyed
            {
                Derived instance(test_num++);
            }
        }
#endif
#if(0)  //test variadic templates
        TestVariadicTemplate::run(std::tuple {10, 20, 3.14, "Hello World!", true});
#endif
#if(1) // move semantic
    {
        int test_num = 1;
        std::cout << "  -=-=-=-Test(" << (test_num++) << ")-=-=-=-\n";
        //( constructors )
        //( factory )
        //( move constructors)
        //( destroy)
        //( destructor)
        TestMoveSemantic b1 = TestMoveSemantic::factory("123");

        std::cout << "  -=-=-=-Test(" << (test_num++) << ")-=-=-=-\n";
        //( copy constructors )
        TestMoveSemantic b2 = b1;

        std::cout << "  -=-=-=-Test(" << (test_num++) << ")-=-=-=-\n";
        //( constructors )
        //( factory )
        //( move constructors)
        //( destroy)
        //( destructor)
        //( destroy)
        //( move assignment operator)
        //( destroy)
        //( destructor)
        b2 = TestMoveSemantic::factory("123");

        std::cout << "  -=-=-=-Test(" << (test_num++) << ")-=-=-=-\n";
        // ( destroy )
        // ( copy assignment operator )
        b2 = b1;

        std::cout << "  -=-=-=-Test(" << (test_num++) << ")-=-=-=-\n";
        //( constructors )
        //( copy constructors )
        TestMoveSemantic b3(*new TestMoveSemantic("345"));

        std::cout << "  -=-=-=-Test(" << (test_num++) << ")-=-=-=-\n";
        // ( constructors )
        TestMoveSemantic b4(TestMoveSemantic("345"));

        //( destroy)
        //( destructor)
        //( destroy)
        //( destructor)
        //( destroy)
        //( destructor)
        //( destroy)
        //( destructor)
    }
#endif
#if(0)
    res = forward_iterator::test_it();
#endif
    return res;
}
