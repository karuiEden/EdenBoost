//
// Created by karui on 11/8/2025.
//

#include "Tree.h"

#include <stdexcept>

namespace EdenBoost
{

    bool Tree::is_leaf(bst_node_t nid) const
    {
        return data[nid].is_leaf();
    }

    float Tree::predict(bst_node_t nid) const
    {
        if (is_leaf(nid)) return data[nid].leaf_value();
        if (data[nid])
    }



} // namespace EdenBoost
