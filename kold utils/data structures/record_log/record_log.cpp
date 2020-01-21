#include "record_log.hpp"

size_t RecordLog::_buffer_size = 0x2000; // 8k

RecordLog::RecordLog(const std::string logName)
        :_buffer(_buffer_size)
{
        _log.open(logName, std::fstream::app);
}

std::streampos RecordLog::AddRecord(const std::string record)
{
        std::streampos pos = _log.tellp();        

        if (!_buffer.Write(record))
        {               
                if (!_buffer.Dump(_log).Write(record))
                {
                        _log.write(record.data(), record.length());
                }
        }

        return pos;
}

RecordLog::~RecordLog()
{
       _buffer.Dump(_log);

        _log.close();
}