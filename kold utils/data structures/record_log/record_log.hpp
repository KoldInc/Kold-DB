#ifndef RECORD_LOG_HPP
#define RECORD_LOG_HPP

#include <fstream>
#include <string>

class RecordLog
{
private:
        std::fstream _log;

public:
        explicit RecordLog(const std::string logName);
        ~RecordLog();

        RecordLog& AddRecord(const std::string record);
};



#endif // RECORD_LOG_HPP