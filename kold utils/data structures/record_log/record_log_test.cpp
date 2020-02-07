


#include <iostream>
#include <cstring>
#include <string>
#include "record_log.hpp"


int main(int argc, char const *argv[])
{

        std::string s("hello th\0ere\n");

        std::cout << std::hex << std::hash<std::string>{}(s);
        // RecordLog test("rl_test");

        // test.AddRecord("this is a test \n").AddRecord("another one\n");

        
        // for (size_t i = 0; i < 0x50000; i++)
        // {
        //         test.AddRecord("record#" + std::to_string(i) + '\n');
        // }

        // char* big_entry = new char[0x10000 * 45];

        // for (size_t i = 0; i < 0x10000; i++)
        // {
        //         memmove(big_entry + (i * 8), &i, 8);
        // }

        // test.AddRecord(big_entry);        


        // delete[] big_entry;

        return 0;
}
