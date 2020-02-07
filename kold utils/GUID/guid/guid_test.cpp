
#include <iostream>

#include "guid.hpp"



int main(int argc, char const *argv[])
{
        utils::GUID::Init();

        utils::GUID g1;
        utils::GUID g2;


        std::cout << std::boolalpha << g1.ToString() << '\n' << g2.ToString() << '\n' << (g1 == g2) << '\n';
        
        return 0;
}
