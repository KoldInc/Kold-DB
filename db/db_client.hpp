#ifndef BASIC_KOLDDB_CLIENT_HPP
#define BASIC_KOLDDB_CLIENT_HPP


#include <string>
#include <list>
#include <map>

#include "serializer.hpp"
#include "table.hpp"

class DBClient
{
private:
        const std::string _rootDir;
        std::vector<std::string> _tables;
        
        DBClient(const std::string& dbRootDir);
        ~DBClient();
public:

        static DBClient* OpenDB(const std::string& dbRootDir);
        static DBClient* CreateDB(const std::string& dbRootDir);

        void Config(const std::string& configProp, const std::string& value);
        void Config(std::list<const std::string&> configProps, std::list<const std::string&> values);

        Table& AddTable(const std::string& tableName, size_t initialNumberOfPartitions = 1);
        Table& GetTable(const std::string& tableName);
        void DeleteTable(const std::string& tableName);
        

        std::list<const std::string&> Tables() const;
};

#endif // BASIC_KOLDDB_CLIENT_HPP