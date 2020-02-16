#ifndef KOLD_BPP_TREE_HPP
#define KOLD_BPP_TREE_HPP

#include <string>

#include "sorted_bag.hpp"

template<typename T, size_t size>
class Btree
{
private:
        class Node
        {
        private:
                SortedBag<std::pair<std::string&, T&>, size> _slots;
                std::array<Node*, size +1> _children;

        public:
                Node();
                Node& Next() const;
                Node& Prev() const;
        };

        Node _root;
public:
        Btree();
        ~Btree();

        T& Put(const std::string& key, T& value);
        T& Get(const std::string key);
        T& Delete(const std::string key);
};

template<typename T, size_t size>
T& Btree<T, size>::Put(const std::string& key, T& value)
{
        if (!_root._slots.Full())
        {
                _root._slots.Insert(std::make_pair(key, value));
        }
}

#endif // KOLD_BPP_TREE_HPP