// 2 trees are identical or not 
// https://leetcode.com/problems/same-tree/description/
/*Same Tree
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
*/
/*
Input: p = [1,2,3], q = [1,2,3]
Output: true
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
         if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        else{
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};
