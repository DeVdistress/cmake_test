#include "test_shared_ptr.h"
#include "test_variadic_templates.h"

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
#if(1)  //test variadic templates
        TestVariadicTemplate::run(std::tuple {10, 20, 3.14, "Hello World!", true});
#endif
#if(1) // move construct
    TestClass b1 = TestClass::factory("123");	// срабатывает конструктор перемещения
    TestClass b2 = b1;							// срабатывает конструктор копирования
    b2 = TestClass::factory("123");				// срабатывает конструктор перемещения, затем оператор перемещения
    b2 = b1;									// срабатывает оператор присваивания
    TestClass b3(*new TestClass("345"));
    TestClass b4(TestClass("345"));
#endif
        return 0;
}
