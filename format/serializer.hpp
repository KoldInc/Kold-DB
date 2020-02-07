#ifndef __KOLD_FORMAT_SERIALIZER
#define __KOLD_FORMAT_SERIALIZER

#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class KoldFormatSerializer
{
private:

public:
        KoldFormatSerializer();
        ~KoldFormatSerializer();

        static std::vector<size_t>& TablePartitions(const std::string& tableRootDir);
        static std::vector<std::string>& DBTables(const std::string& dbRootDir);
};

std::vector<std::string>& KoldFormatSerializer::DBTables(const std::string& dbRootDir)
{
        std::vector<std::string>* tables = new std::vector<std::string>();
        std::ifstream input(dbRootDir + "/_meta.metadata");

        std::string tableName;

        while (std::getline(input, tableName, ','))
        {
                tables->push_back(tableName);
        }
        
        return *tables;
}

std::vector<size_t>& KoldFormatSerializer::TablePartitions(const std::string& tableRootDir)
{
        std::vector<size_t>* partitions = new std::vector<size_t>();
        std::ifstream input(tableRootDir + "/_meta.metadata", std::fstream::in);

        std::string part;


        while (std::getline(input, part, ','))
        {
                partitions->push_back(std::stoul(part, nullptr, 16));
        }
        
        return *partitions;
}




#endif // __KOLD_FORMAT_SERIALIZER
