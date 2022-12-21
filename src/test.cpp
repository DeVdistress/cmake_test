#include<iostream>
#include <list>

int main(){
        auto i = 1;

        std::cout << std::boolalpha << i <<"\n";

        auto ls = std::list<int>({1, 2, 3, 4, 5});
        for (const auto i : ls) {
            std::cout << i << std::endl;
        }

        return 0;
}
