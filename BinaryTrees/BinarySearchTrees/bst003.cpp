// Max and min element in Binary Tree
// https://www.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
/*
Given a Binary Tree, find maximum and minimum elements in it.

Example 1:

Input: 
           
Output: 11 1
Explanation:                           
 The maximum and minimum element in 
this binary tree is 11 and 1 respectively.
Input: 
           6
        / \
       5   8
      /
     2
Output: 8 2

You don't need to read input or print anything. Your task is to complete findMax() and findMin() functions which take root node of the tree as input parameter and return the maximum and minimum elements in the binary tree respectively.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

*/
class Solution
{
public:
    int findMax(Node *root)
    {
        //code here
          
        Node *temp=root;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        return temp->data;
    }
    int findMin(Node *root)
    {
        //code here
         Node *temp=root;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        return temp->data;
    }
};
