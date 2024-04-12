// Count Leaves in Binary Tree
// https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1
/*
Count Leaves in Binary Tree
BasicAccuracy: 76.44%Submissions: 106K+Points: 1
Given a Binary Tree of size N, You have to count leaves in it. For example, there are two leaves in following tree

        1
     /      \
   10      39
  /
5
*/
/*

Input:
Given Tree is 
               4
             /   \
            8     10
           /     /   \
          7     5     1
         /
        3 
Output:
3
Explanation: 
Three leaves are 3 , 5 and 1.
 

Your Task:
You don't have to take input. Complete the function countLeaves() that takes root node of the given tree as parameter and returns the count of leaves in tree. The printing is done by the driver code.
 
 */

int countLeaves(Node* root)
{
  // Your code here
  int count=0;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
      Node* act_root=q.front();
      q.pop();
      if(act_root->left){
          q.push(act_root->left);
      }
      if(act_root->right){
          q.push(act_root->right);
      }
      if(!act_root->left && !act_root->right){
          count++;
      }
  }
  return count;
}
