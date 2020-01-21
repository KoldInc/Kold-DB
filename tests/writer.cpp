

#include "table.hpp"
#include "format.hpp"

int main(int argc, char const *argv[])
{
        // create a table
        Table* table = new Table();

        // populate with entries from mock data
        table->AddEntry("name", "allan");
        const FileEntry entry = { "mails", "a@b.com,d@e.ru" };
        table->AddEntry(entry);

        // compare written file to mock data


        // exit

        // use this table for reader test
        
        
        return 0;
}
