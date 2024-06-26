// Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/description/
/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []

*/
class Solution {
public:
    void solve(TreeNode* root,vector<int> &ans,int level){

        if(root==NULL){
            return ;
        }
        if(level==ans.size()){
            ans.push_back(root->val);
        }
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root,ans,0);
        return ans;
    }
};
