

#include "guid.hpp"
#include <climits>
#include <sstream>
#include <unistd.h>


#include <iostream>


namespace utils
{

std::mt19937_64 GUID::_rnd_engine;
std::stringstream GUID::_stream;
std::mutex GUID::_stream_lock;



GUID::GUID()
        :_seg_1(_rnd_engine()), _seg_2(_rnd_engine()), _str(MakeStr())
{}

const std::string GUID::MakeStr() const
{
        uint_fast32_t segment_1 = (_seg_1 >> 32) & UINT_FAST32_MAX;
        uint_fast16_t segment_2 = ((_seg_1 << 32) >> 48) & UINT_FAST16_MAX;

        uint_fast16_t segment_3 = ((_seg_1 << 48) >> 48) & UINT_FAST16_MAX;
        uint_fast16_t segment_4 = (_seg_2 >> 48) & UINT_FAST16_MAX;

        uint_fast64_t segment_5 = (_seg_2 << 16) >> 16;


        _stream_lock.lock();

        _stream.str("");

         _stream << std::hex << (segment_1) << '-' <<
                (segment_2) << '-' <<
                (segment_3) << '-' << 
                (segment_4) << '-' <<
                (segment_5);  

        std::string str = _stream.str();

        _stream_lock.unlock();

        return str;
}

void GUID::Init()
{
        _rnd_engine.seed(getpid() + time(nullptr));
}

bool GUID::operator==(const GUID& b)
{
        return (_seg_1 == b._seg_1) && (_seg_2 == b._seg_2);
}

const std::string& GUID::ToString() const
{
        return _str;
}

}

