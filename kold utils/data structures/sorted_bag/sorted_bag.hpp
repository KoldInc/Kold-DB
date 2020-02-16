#ifndef SORTED_BAG_HPP
#define SORTED_BAG_HPP

#include <array>
#include <map>
#include <iosfwd>

template <typename T, size_t size>
class SortedBag
{        
private:
        std::array<std::pair<std::string, T>, size> _array;
        size_t _insertIndex;
public:
        SortedBag() : _insertIndex(0) {}
        ~SortedBag() {}

        const T& operator[](size_t index) const { return _array[index].second; } 

        inline size_t Occupancy() const { return _insertIndex; }
        inline bool Full() const { return _insertIndex == size; }

        SortedBag& Insert(std::string& key, T value);
        SortedBag& Remove(size_t index);
};


template <typename T, size_t size>
SortedBag<T, size>& SortedBag<T, size>::Insert(std::string& key, T value)
{
        if (size <= _insertIndex) return *this;

        std::pair<std::string, T> insertVal = std::make_pair(key, value);

        size_t slot(0);
        while (_insertIndex > slot)
        {
                if (key < _array[slot].first)
                {
                        std::swap(insertVal, _array[slot]);
                }

                ++slot;
        }

        _array[_insertIndex] = insertVal;
        ++_insertIndex;

        return *this;
}


template <typename T, size_t size>
std::ostream& operator<<(std::ostream& os, SortedBag<T, size>& sb)
{
        for (size_t i = 0; i < sb.Occupancy(); i++)
        {
                os << sb[i] << ',';
        }

        os << '\n';

        return os;
}


#endif //SORTED_BAG_HPP