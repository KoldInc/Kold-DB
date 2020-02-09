
#include <algorithm>
#include <sstream>
#include "table.hpp"

const std::string Table::_delete_value("DELETE-ME-PLS-b0ss");

Table::Table(const std::string& tableRootDir, std::vector<size_t>& partitions)
        : _rootDir(tableRootDir), _partitions(partitions)
{}

const std::string Table::ToString() const
{
        std::stringstream partitions;

        partitions << std::hex;

        for (auto iter = _partitions.begin(); iter != _partitions.end(); ++iter)
        {
                partitions << *iter << ',';
        }

        partitions << '\n';

        std::string* rv = new std::string(_rootDir + '\n' + partitions.str());
        
        return *rv;
}