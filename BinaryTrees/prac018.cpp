// Path Sum III
// https://leetcode.com/problems/path-sum-iii/description/

/*
Path Sum III
Given the root of a binary tree and an integer targetSum,
return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards 
(i.e., traveling only from parent nodes to child nodes).
*/
class Solution {
public:
    void solve(TreeNode* root, int k, int &count, std::vector<int>& path) {
        // base case
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);

        // left
        solve(root->left, k, count, path);
        // right
        solve(root->right, k, count, path);

        // check for k Sum
        int sum = 0;
        for (int i = path.size() - 1; i >= 0; i--) {
            sum += path[i];
            if (sum == k) {
                count++;
            }
        }
        path.pop_back();
    }

    int pathSum(TreeNode* root, int targetSum) {
        std::vector<int> path;
        int count = 0;
        solve(root, targetSum, count, path);
        return count;
    }
};
// time complexity ->O(n)
