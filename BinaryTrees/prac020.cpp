// Maximum sum of Non-adjacent nodes
// https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

/*
Maximum sum of Non-adjacent nodes
MediumAccuracy: 55.35%Submissions: 60K+Points: 4
Given a binary tree with a value associated with each node,
 we need to choose a subset of these nodes such that sum of chosen nodes 
 is maximum under a constraint that no two chosen node in subset should be 
 directly connected that is, 
 if we have taken a node in our sum then we can’t take its any 
 children or parents in consideration and vice versa.

 Input:
     11
    /  \
   1    2
Output: 11
Explanation: The maximum sum is sum of
node 11.

Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.

*/
class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node* root){
        // base case
        if(root==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
        }
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        
        pair<int,int> res;
        res.first=root->data+left.second+right.second;//including the current node
        res.second=max(left.first,left.second)+max(right.first,right.second);
        return res;
        
    }
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int,int> ans=solve(root);
        return max(ans.first,ans.second);
        
    }
};
/*
Building the Tree: Before we can calculate the maximum sum of non-adjacent nodes,
 we need to build the binary tree from the given input string. Building the tree involves parsing the input string and creating nodes. This process has a time complexity of O(N), where N is the number of nodes in the tree.

Calculating Maximum Sum: The solve function is called recursively for each node in the tree. At each node, we perform constant time operations to calculate the maximum sum of non-adjacent nodes. Since we visit each node once, the time complexity of this step is also O(N).

*/
