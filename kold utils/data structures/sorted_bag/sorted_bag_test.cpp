

#include <iostream>

#include "sorted_bag.hpp"


int main(int argc, char const *argv[])
{
        SortedBag<int, 5> test;

        test.Insert(6);
        test.Insert(4);


        std::cout << test;


        
        return 0;
}

