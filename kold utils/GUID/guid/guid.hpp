
#include <cstdint>
#include <string>
#include <random>
#include <mutex>


namespace utils
{


class GUID
{
private:
        uint_fast64_t _seg_1;
        uint_fast64_t _seg_2;
        const std::string _str;

        static std::mt19937_64 _rnd_engine;
        static const std::string _str_rep_with_dashes;
        static const std::string _str_rep_no_dashes;
        static std::stringstream _stream;
        static std::mutex _stream_lock;

        const std::string MakeStr() const;

public:
        GUID();
        // ~GUID() = delete;

        const std::string& ToString() const;
        bool operator==(const GUID& b);

        static void Init();

        
};

}
