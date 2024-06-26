// Left View of Binary Tree
// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
/*
Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument. If no left view is possible, return an empty tree.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3
*/
void solve(Node* root,vector<int> &ans,int level){
    // base case
    if(root==NULL){
       return ;
   }
   
//   we entered into a new level
   if(level==ans.size()){
       ans.push_back(root->data);
   }
   
   
   solve(root->left,ans,level+1);
   solve(root->right,ans,level+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   solve(root,ans,0);
   return ans;
   
}
