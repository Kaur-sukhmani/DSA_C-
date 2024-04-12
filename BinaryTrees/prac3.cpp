// Height of Binary Tree
// https://www.geeksforgeeks.org/problems/height-of-binary-tree/1
// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

/*
Given a binary tree, find its height.
Input:
     1
    /  \
   2    3
Output: 2

Example 2:
Input:
  2
   \
    1
   /
 3
Output: 3  
*/
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // base case
        if(node==NULL){
            return NULL;
        }
        int left=height(node->left);
        int right=height(node->right);
        
        int ans=max(left,right)+1;
        return ans;
    }
};

// TC=O(n)
 
