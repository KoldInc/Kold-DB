

#include <fstream>

#include "db_client.hpp"


DBClient* DBClient::OpenDB(const std::string& dbRootDir)
{
        DBClient* client = new DBClient(dbRootDir);

        return client;
}

DBClient::DBClient(const std::string& dbRootDir)
        : _rootDir(dbRootDir) ,_tables(KoldFormatSerializer::DBTables(_rootDir))
{}

Table& DBClient::GetTable(const std::string& tableName)
{
        std::string tableRootDir(_rootDir + "/tables/" + tableName + '/');        

        Table* table = new Table(tableRootDir, KoldFormatSerializer::TablePartitions(tableRootDir));

        return* table;
}

Table& DBClient::AddTable(const std::string& tableName, size_t initialNumberOfPartitions = 1)
{
        // create table directory (how)

        // calculate hash ranges by initialNumberOfPartitions

        // create tableName_meta.metadata. write partition ranges into it

        // create initialNumberOfPartitions partition files
}

