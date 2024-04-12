// Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/description/
/*
Input: root = [3,9,20,null,null,15,7]
Output: true
*/
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);

        return 1+max(leftHeight,rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int left=height(root->left);
        int right=height(root->right);
        int diff=right-left;
        if(abs(diff)<=1){
            return true;
        }
        else{
            return false;
        }
    }
};
/*
Intuition
The first approach uses a recursive function to calculate the height of each subtree and then checks if the tree is balanced based on the heights of its left and right subtrees.

Approach 1
Define a helper function height that calculates the height of a subtree.
In the height function, recursively calculate the height of the left and right subtrees.
Return the maximum height of the left and right subtrees plus 1 (the height of the current node).
In the isBalanced function, check if the tree is balanced by comparing the heights of its left and right subtrees and ensuring that their absolute difference is at most 1.
Recursively call the isBalanced function for both the left and right subtrees.
If the tree is balanced and both left and right subtrees are balanced, return true; otherwise, return false.
Complexity
Time complexity: O(n^2) in the worst case, where n is the number of nodes in the tree. This is because, in the worst case, for each node, we calculate the heights of its left and right subtrees, resulting in a time complexity of O(n) for each node, and there are n nodes in the tree.

Space complexity: O(h), where h is the height of the tree. This is due to the recursive call stack, which can go as deep as the height of the tree.
*/
/*
Approach 2
Define a helper function balanced that returns a pair of values: a boolean indicating whether the subtree is balanced and the height of the subtree.
In the balanced function, recursively calculate the balance status and height of the left and right subtrees.
Check the balance condition by comparing the heights of the left and right subtrees and ensuring that their absolute difference is at most 1.
Return a pair containing the boolean indicating whether the subtree is balanced and the height of the subtree.
In the isBalanced function, return the boolean value of the first element in the pair returned by the balanced function.
Complexity
Time complexity: O(n), where n is the number of nodes in the tree. This is because each node is visited exactly once, and during the visit, the height and balance conditions are checked.

Space complexity: O(h), where h is the height of the tree. This is due to the recursive call stack, which can go as deep as the height of the tree.
*/
pair<bool, int> balanced(TreeNode* root) {
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        pair<bool,int> left=balanced(root->left);
        pair<bool,int> right=balanced(root->right);

        bool leftAns=left.first;
        bool rightAns=right.first;

        int diff=abs(left.second-right.second)<=1; //balanced or not

        pair<bool,int>ans;
        ans.second=max(left.second,right.second )+1; //height

        if(leftAns && rightAns && diff)
            ans.first=true;
        
        else
            ans.first=false;
        return ans;
        
    }
    bool isBalanced(TreeNode* root) {
        return balanced(root).first;
    }
