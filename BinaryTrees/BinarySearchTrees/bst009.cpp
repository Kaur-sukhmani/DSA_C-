Normal Bst to balanced bst
// https://leetcode.com/problems/balance-a-binary-search-tree/description/
// https://www.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1
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
Normal BST to Balanced BST
Difficulty: MediumAccuracy: 66.08%Submissions: 55K+Points: 4
Given a Binary Search Tree, modify the given BST such that it is balanced and has minimum possible height. Return the balanced BST.

Example1:

Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30
Example2:

Input:
         4
        /
       3
      /
     2
    /
   1
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   
    \          /                  \ 
     2        1                    4

Your Task:
The task is to complete the function buildBalancedTree() which takes root as the input argument and returns the root of tree after converting the given BST into a balanced BST with minimum possible height. The driver code will print the height of the updated tree in output itself.
 
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int> &ans, int start, int end) {
        if (start > end) {
            return NULL;
        }

        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(ans[mid]);

        node->left = sortedArrayToBST(ans, start, mid - 1);
        node->right = sortedArrayToBST(ans, mid + 1, end);

        return node;
    }

    // Function to store inorder traversal of the BST
    void inorder_store(TreeNode* root, vector<int> &ans) {
        if (root == NULL) {
            return;
        }

        inorder_store(root->left, ans);
        ans.push_back(root->val);
        inorder_store(root->right, ans);
    }
    TreeNode* balanceBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        // Store inorder traversal of the tree in the vector
        vector<int> ans;
        inorder_store(root, ans);

        // Convert the sorted array to a balanced BST
        return sortedArrayToBST(ans, 0, ans.size() - 1);
    }
};
