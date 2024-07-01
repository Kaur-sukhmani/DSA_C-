// 653. Two Sum IV - Input is a BST
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


/*
I did BFS, added the values level-wise, flattened and sorted the list and
 did the two pointer 2sum check to get the answer. 
 Another approach could be to do the in-order traversal 
 of the tree to get the list of values and then do the 2sum check.
*/


/*SOLUTION 1*/
#include <vector>
using namespace std;

// Define a structure for Binary Tree Node
template<typename T>
struct BinaryTreeNode {
    T data;               // Data stored in the node
    BinaryTreeNode* left; // Pointer to the left child node
    BinaryTreeNode* right; // Pointer to the right child node

    // Constructor to initialize data and pointers
    BinaryTreeNode(T data) : data(data), left(NULL), right(NULL) {}
};

// Function to perform inorder traversal of a binary search tree (BST)
void inorder(BinaryTreeNode<int>* root, vector<int>& in) {
    if (root == NULL)
        return; // Base case: if root is NULL, return

    inorder(root->left, in); // Traverse left subtree
    in.push_back(root->data); // Push current node's data to vector
    inorder(root->right, in); // Traverse right subtree
}

// Function to find if there are two elements in the BST that sum up to a target
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    vector<int> inorderVal; // Vector to store inorder traversal of BST
    inorder(root, inorderVal); // Perform inorder traversal and populate inorderVal

    int i = 0, j = inorderVal.size() - 1; // Initialize two pointers for two-sum check

    // Two-pointer technique to find if two elements sum up to target
    while (i < j) {
        int sum = inorderVal[i] + inorderVal[j]; // Calculate sum of current elements
        if (sum == target)
            return true; // Found two elements that sum up to target
        else if (sum > target)
            j--; // Decrease right pointer to decrease the sum
        else
            i++; // Increase left pointer to increase the sum
    }
    return false; // No such pair found
}

Time Complexity: O(n) for both inorder traversal and twoSumInBST function.
Space Complexity: O(n) for both inorder traversal and twoSumInBST function.


/*SOLUTION 2*/
class Solution {
public:
     bool TwoPointer(TreeNode* root, int k, vector<int>& ans) {
        int n = ans.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (ans[i] + ans[j] == k) {
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> solve(TreeNode* root,int k) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        return ans;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans= solve(root,k);
        return TwoPointer(root,k,ans);
    }
};
