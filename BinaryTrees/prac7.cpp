// Sum Tree
// https://www.geeksforgeeks.org/problems/sum-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
/*
MediumAccuracy: 37.17%Submissions: 216K+Points: 4
Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.

An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.
*/
/*
Input:
    3
  /   \    
 1     2

Output: 1
Explanation:
The sum of left subtree and right subtree is
1 + 2 = 3, which is the value of the root node.
Therefore,the given binary tree is a sum tree.
*/
class Solution{
public:
    bool isLeaf(Node* node) {
        return (node != NULL && node->left == NULL && node->right == NULL);
    }

    bool isSumTree(Node* root)
    {
        if (root == NULL || isLeaf(root)) {
            return true;
        }

        int leftSum = 0, rightSum = 0;

        if (isSumTree(root->left) && isSumTree(root->right)) {
            if (root->left == NULL) {
                leftSum = 0;
            } else if (isLeaf(root->left)) {
                leftSum = root->left->data;
            } else {
                leftSum = 2 * (root->left->data);
            }

            if (root->right == NULL) {
                rightSum = 0;
            } else if (isLeaf(root->right)) {
                rightSum = root->right->data;
            } else {
                rightSum = 2 * (root->right->data);
            }

            return (root->data == leftSum + rightSum);
        }

        return false;
    }
};
