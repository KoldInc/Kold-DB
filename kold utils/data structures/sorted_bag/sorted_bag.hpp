#ifndef SORTED_BAG_HPP
#define SORTED_BAG_HPP

#include <array>
#include <iosfwd>

template <typename T, size_t size>
class SortedBag
{        
private:
        std::array<T, size> _array;
        size_t _insertIndex;
public:
        SortedBag() : _insertIndex(0) {}
        ~SortedBag() {}

        const T& operator[](size_t index) const { return _array[index]; } 

        inline const size_t Occupancy() const { return _insertIndex; }

        SortedBag& Insert(T value);
        SortedBag& Remove(size_t index);
};


template <typename T, size_t size>
SortedBag<T, size>& SortedBag<T, size>::Insert(T value)
{
        // compare each slot to [value]. when value > [i], start swapping

        if (size <= _insertIndex) return *this;

        size_t slot(0);
        while (_insertIndex > slot)
        {
                if (value < _array[slot])
                {
                        std::swap(value, _array[slot]);
                }

                ++slot;
        }

        if (slot < size)
        {
                _array[slot] = value;
                ++_insertIndex;
        }

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