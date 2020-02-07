
#include <map>

static const size_t NUM_REPLICATIONS(3);

class DbNode
{

private:
        std::pair<size_t, size_t> _hash_range;
        DbNode* _replicators[NUM_REPLICATIONS];
public:
        DbNode(/* args */);
        ~DbNode();
};


DbNode::DbNode(/* args */)
{

}

DbNode::~DbNode()
{
}
