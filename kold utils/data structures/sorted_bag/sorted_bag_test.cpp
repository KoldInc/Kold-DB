

#include <iostream>

#include "sorted_bag.hpp"


int main(int argc, char const *argv[])
{
        SortedBag<int, 5> test;

        int bobKilo(6);
        int aliceKilo(4);
        std::string bobName("bob");
        std::string aliceName("alice");

        test.Insert(bobName, bobKilo);
        test.Insert(aliceName, aliceKilo);


        std::cout << test;


        
        return 0;
}

