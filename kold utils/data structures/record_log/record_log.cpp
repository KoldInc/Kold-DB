#include <iostream>
#include "record_log.hpp"


RecordLog::RecordLog(const std::string logName)
{
        _log.open(logName, std::fstream::app);
}

RecordLog& RecordLog::AddRecord(const std::string record)
{        
        _log.write(record.data(), record.length());

        return *this;
}

RecordLog::~RecordLog()
{
        _log.sync();
        _log.close();
}