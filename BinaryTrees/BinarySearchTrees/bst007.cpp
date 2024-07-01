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
