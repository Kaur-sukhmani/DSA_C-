// Boundary Traversal of binary tree
// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
/*
Given a Binary Tree, find its Boundary Traversal. 
The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node
ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root.
The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. 
Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Input:
        1 
      /   \
     2     3  
    / \   / \ 
   4   5 6   7
      / \
     8   9
   
Output: 1 2 4 8 9 6 7 3
Explanation:
*/
class Solution {
public:
    void printLeftBoundary(Node* root,vector<int>&ans){
        if(!root)return;
        
        if(!root->left && !root->right)return;
        
        ans.push_back(root->data);
        if(root->left)
            printLeftBoundary(root->left,ans);
        else
            printLeftBoundary(root->right,ans);
    }
    void printLeafBoundary(Node* root,vector<int>&ans){
        if(!root)return;
        
        if(!root->left && !root->right){
            ans.push_back(root->data);
        }
        printLeafBoundary(root->left,ans);
        printLeafBoundary(root->right,ans);
    }
    void printRightBoundary(Node* root,vector<int>&ans){
        if(!root)return;
        
        if(!root->left && !root->right)return;
        
        if(root->right)
            printRightBoundary(root->right,ans);
        else
            printRightBoundary(root->left,ans);
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(!root){
            return ans;
        }
        ans.push_back(root->data);
        // left Subtrree
        printLeftBoundary(root->left,ans);

        // leaf nodes
        printLeafBoundary(root->left,ans);
        printLeafBoundary(root->right,ans);
        
        // right Subtree
        printRightBoundary(root->right,ans);
        return ans;
    }
};
