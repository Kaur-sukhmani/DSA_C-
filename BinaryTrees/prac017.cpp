// Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q 
as the lowest node in T that has both p and q as descendants
 (where we allow a node to be a descendant of itself).”*/

 /* example
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4
Let's say we want to find the lowest common ancestor of nodes p = 5 and q = 1.*/
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        // If the current node is NULL, return NULL
        if (root == NULL)
            return NULL;

        // If the current node is one of the nodes we are searching for (p or q),
        // return the current node
        if (root == p || root == q)
            return root;

        // Recursively search in the left subtree for nodes p and q
        TreeNode* left = solve(root->left, p, q);

        // Recursively search in the right subtree for nodes p and q
        TreeNode* right = solve(root->right, p, q);

        // If both p and q are found in different subtrees, then root is the
        // lowest common ancestor
        if (left && right)
            return root;

        // If one of the subtrees returns a non-null value (either p or q),
        // then that is the lowest common ancestor found so far
        if (left != nullptr) {
            return left;
        } 
        else {
            return right;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};
