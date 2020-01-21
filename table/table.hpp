#ifndef KOLD_DB_TABLE_HPP
#define KOLD_DB_TABLE_HPP

#include <iosfwd>
#include <map>

#include "format.hpp"
#include "record_log.hpp"

class Table
{
private:
        std::fstream& _file;                      // shon: does table know about files? shouldn't this part go into the formatter?       
        
        std::map<std::string&, IndexItem> _index; // shon: aren't keys supposed to be timestamps? so the size of them will be fixed?
        RecordLog& _log;

public:
        Table(void* mmapped_file);
        ~Table();

        IndexItem& AddEntry(const FileEntry& entry) { _log.AddRecord(entry); return entry; }
        IndexItem& AddEntry(std::string key, std::string value);

        IndexItem& DeleteEntry(FileEntry& entry);
        IndexItem& DeleteEntry(std::string& key);
        IndexItem& DeleteEntry(IndexItem& indexItem);

        std::string& GetEntry(const FileEntry& entry);
        std::string& GetEntry(const std::string& key);
        std::string& GetEntry(const IndexItem& indexItem);
};



#endif // KOLD_DB_TABLE_HPP

