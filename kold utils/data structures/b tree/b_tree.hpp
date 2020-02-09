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
                SortedBag<T&, size> _slots;
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

#endif // KOLD_BPP_TREE_HPP