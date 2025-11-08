//
// Created by karui on 11/8/2025.
//

#ifndef EDENBOOST_TREE_H
#define EDENBOOST_TREE_H
#include "TreeNode.h"
#include <vector>
namespace EdenBoost
{

    class Tree
    {
        std::vector<Node> data;
    public:
        Tree() = default;

        void add(Node& node);

        [[nodiscard]] bool is_leaf(bst_node_t nid) const;

        [[nodiscard]] float predict(bst_node_t nid) const;

    };

} // namespace EdenBoost

#endif // EDENBOOST_TREE_H
