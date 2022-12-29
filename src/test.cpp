#include "test_shared_ptr.h"
#include "test_variadic_templates.h"
#include "test_move_semantics.h"

int main() {
#if(0)  //test linking of c++abi"
        std::cout << std::boolalpha << true << "\n";
#endif
#if(0)  //test shared_ptr
        // Please see   https://stackoverflow.com/questions/2254263/order-of-member-constructor-and-destructor-calls
        //              https://habr.com/ru/post/191018/ 
        {
            // this works well
            {
                Derived instance(0);
            }

            // this works well
            {
                Derived instance(1);
            }

            // first_one will be destroyed before second_one 
            {
                Derived instance(2);
            }

            // first_one and second_one won't be destroyed
            {
                Derived instance(3);
            }
        }
#endif
#if(0)  //test variadic templates
        TestVariadicTemplate::run(std::tuple {10, 20, 3.14, "Hello World!", true});
#endif
#if(1) // move construct
    {
        int test_num = 1;
        std::cout << "  -=-=-=-Test(" << (test_num++) << ")-=-=-=-\n";
        //( Constructors )
        //( TestMoveSemantic's Factory )
        TestMoveSemantic b1 = TestMoveSemantic::factory("123");

        std::cout << "  -=-=-=-Test(" << (test_num++) << ")-=-=-=-\n";
        //( Copy constructors )
        TestMoveSemantic b2 = b1;

        std::cout << "  -=-=-=-Test(" << (test_num++) << ")-=-=-=-\n";
        //( Constructors )
        //( Factory )
        //( Destructor )
        //( Move assignment operator )
        //( Destructor )
        b2 = TestMoveSemantic::factory("123");

        std::cout << "  -=-=-=-Test(" << (test_num++) << ")-=-=-=-\n";
        //( Destructor )
        //( Copy assignment operator )
        b2 = b1;

        std::cout << "  -=-=-=-Test(" << (test_num++) << ")-=-=-=-\n";
        //( Constructors )
        //( Copy constructors )
        TestMoveSemantic b3(*new TestMoveSemantic("345"));

        std::cout << "  -=-=-=-Test(" << (test_num++) << ")-=-=-=-\n";
        //( Constructors )
        TestMoveSemantic b4(TestMoveSemantic("345"));

        //( Destructor )
        //( Destructor )
        //( Destructor )
        //( Destructor )
    }
#endif
        return 0;
}
