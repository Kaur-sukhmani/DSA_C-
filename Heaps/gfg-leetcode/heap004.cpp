// Is Binary Tree Heap
// https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1
/*
Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Example 1:

Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.

Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0

Your Task:
You don't need to read input or print anything. Your task is to complete the function isHeap() which takes the root of Binary Tree as parameter returns True if the given binary tree is a heap else returns False.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)

Constraints:
1 ≤ Number of nodes ≤ 100
1 ≤ Data of a node ≤ 1000
*/
class Solution {
  public:
    void countNodes(struct Node* &tree,int &count){
        if(tree==NULL){
            return ;
        }
        count++;
        if(tree->left){
            countNodes(tree->left,count);
        }
        if(tree->right){
            countNodes(tree->right,count);
        }
    }
    
    bool isCBT(struct Node* tree,int index,int totalNodes){
        if(tree==NULL){
            return true;
        }
        if(index >= totalNodes){ //equal to ka case is liye kyunki 0 base indexing kar rhe hain
            return false;
        }
        else{
            bool left=isCBT(tree->left,2*index+1,totalNodes);
            bool right=isCBT(tree->right,2*index+2,totalNodes);
            return left && right;
        }
    }
    bool isMaxOrder(struct Node* tree){
        // leaf node
        if(tree->left==NULL && tree->right==NULL){
            return true;
        }
        // since it is a cBT 
        if(tree->right==NULL){
            return tree->data > tree->left->data;
        }
        // dono chila hai 
        else{
            return tree->data > tree->left->data &&
                    tree->data > tree->right->data && 
                    isMaxOrder(tree->left) && 
                    isMaxOrder(tree->right);
        }
    }
    bool isHeap(struct Node* tree) {
        // code here
        int index=0;
        int count=0;
        
        countNodes(tree,count);
        int totalCount= count;
        if(isCBT(tree,index,totalCount) && isMaxOrder(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};
// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)

// Appraoc 2 
    /*
    int countNodes(struct Node* &tree){
        if(tree==NULL){
            return 0;
        }
        int ans=1+countNodes(tree->left)+countNodes(tree->right);
        return ans;
    }
    bool isHeap(struct Node* tree) {
        // code here
        int index=0;
        int count=0;
        
        int totalCount=countNodes(root,count);
        
        if(isCBT(tree,) && isMaxOrder()){
            return true;
        }
        else{
            return false;
        }
    }*/
