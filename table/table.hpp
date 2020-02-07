#ifndef KOLD_DB_TABLE_HPP
#define KOLD_DB_TABLE_HPP

#include <iosfwd>
#include <map>
#include <forward_list>
#include <string>
#include <vector>

#include "b_tree.hpp"

class Table
{
private:

        static const std::string _delete_value;

        const std::string _rootDir;        
        std::vector<size_t> _partitions;
        std::map<const std::string, const std::string> _index;
        Btree<std::string, 6> _table;

public:
        Table(const std::string& tableRootDir, std::vector<size_t>& partitions);
        ~Table();

        bool Put(const std::string& key, const std::string& value);
        std::pair<std::string, std::string> Get(const std::string& key) const;
        std::pair<std::string, std::string> Delete(const std::string& key);


        const std::string ToString() const; // print out all partitions, indexes
};


#endif // KOLD_DB_TABLE_HPP

