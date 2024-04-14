// Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
/*Binary Tree Zigzag Level Order Traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
 (i.e., from left to right, then right to left for the next level and alternate between)*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        int f=0;
        while(!q.empty()){
            vector<int> temp;
            int size=q.size();
            while(size--){
                TreeNode* te=q.front();
                q.pop();
                if(te->left){
                    q.push(te->left);
                }
                if(te->right){
                    q.push(te->right);
                }
                temp.push_back(te->val);
            }
            if(f==0){
                ans.push_back(temp);
                f=1;
            }
            else{
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                f=0;
            }

        }
        return ans;
    }
};
