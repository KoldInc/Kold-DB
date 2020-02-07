

#include <iostream>

#include "table.hpp"
#include "serializer.hpp"


int main(int argc, char const *argv[])
{
        const std::string root("../sample_db/tables/table_a");
        Table* test(new Table(root, KoldFormatSerializer::TablePartitions(root)));


        std::cout << test->ToString();

        

        return 0;
}
