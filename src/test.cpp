#include "test_shared_ptr.h"
#include <iostream>

int main() {
#if(1)  //test linking of c++abi"
        std::cout << std::boolalpha << true << "\n";
#endif
#if(1)  //test shared_ptr
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
        return 0;
}
