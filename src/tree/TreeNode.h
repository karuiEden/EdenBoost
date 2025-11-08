//
// Created by karui on 11/8/2025.
//

#ifndef EDENBOOST_TREENODE_H
#define EDENBOOST_TREENODE_H
#include <base.h>

namespace EdenBoost
{
    union Info
    {
        float leaf_value;
        split_cond split_cond;
    };
    class Node
    {
    public:
        static constexpr bst_node_t InvalidNodeID = -1;

        // Getters

        Node(bst_node_t left, bst_node_t right, bst_node_t parent, uint32_t feature, split_cond condition
            , bool default_child): parent_(parent),  left_(left), right_(right), feature_idx_(feature), default_left(default_child)
        {
            info_.split_cond = condition;
        }

        [[nodiscard]] bst_node_t left() const { return left_; }

        [[nodiscard]] bst_node_t right() const { return right_; }

        [[nodiscard]] uint32_t feature_idx() const { return feature_idx_; }

        [[nodiscard]] bst_node_t default_child() const {return is_default_left() ? left_ : right_;}

        [[nodiscard]] bool is_root() const { return parent_ == InvalidNodeID; }

        [[nodiscard]] bool is_left_child() const { return is_left; }

        [[nodiscard]] bool is_default_left() const { return default_left; }

        [[nodiscard]] split_cond split_condition() const { return info_.split_cond; }

        [[nodiscard]] bool is_leaf() const { return left_ == InvalidNodeID; }

        [[nodiscard]] float leaf_value() const { return info_.leaf_value; }



        //Setters

        void set_right(const bst_node_t nid) { right_ = nid; }

        void set_left(const bst_node_t nid) { left_ = nid; }

        void set_split(const split_cond cond, const bool def, const uint32_t fid)
        {
            info_.split_cond = cond;
            feature_idx_ = fid;
            default_left = def;
        }

        void set_leaf_value(const float val)
        {
            info_.leaf_value = val;
            left_ = InvalidNodeID;
            right_ = InvalidNodeID;
        }

        void set_parent(const bst_node_t pid){ parent_ = pid; }



    private:
        bst_node_t parent_{InvalidNodeID};
        bst_node_t left_{InvalidNodeID};
        bst_node_t right_{InvalidNodeID};
        uint32_t feature_idx_{0};
        Info info_{};
        bool default_left{false};
        bool is_left{false};
    };

} // namespace EdenBoost

#endif // EDENBOOST_TREENODE_H
