// Construct Tree from Inorder & Preorder
// https://www.geeksforgeeks.org/problems/construct-tree-1/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
/*
Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
Your Task:
Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)

Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).

*/
class Solution{
    int findPosition(int in[],int startIndex,int element,int n){
        
        for(int i=startIndex;i<n;i++){
            if(in[i]==element){
                return i;
            }
        }
        
        return -1;
    }
    
    Node *solve(int in[],int pre[],int &index,int startIndex,int endIndex,int n){
        
        if(index >=n || startIndex > endIndex ){
            return NULL;
        }
        
        int element=pre[index++];
        Node *root=new Node(element);
        
        int pos=findPosition(in,startIndex,element,n);
        
        root->left=solve(in,pre,index,startIndex,pos-1,n);
        root->right=solve(in,pre,index,pos+1,endIndex,n);
        
        return root;
    }
    
    public:
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preIndex=0;
        Node *ans=solve(in,pre,preIndex,0,n-1,n);
        
        return ans;
    }
};
// OPTIMIZATION->instead of iterating the inorder again and again just store it in a map
class Solution {
public:
    void createMapping(int in[], map<int, int> &nodeToIndex, int n) {
        for (int i = 0; i < n; i++) {
            nodeToIndex[in[i]] = i;
        }
    }

    Node* solve(int in[], int pre[], int &index, int startIndex, int endIndex, int n, map<int, int> &nodeToIndex) {
        if (index >= n || startIndex > endIndex) {
            return nullptr;
        }

        int element = pre[index++];
        Node *root = new Node(element);

        int pos = nodeToIndex[element];

        root->left = solve(in, pre, index, startIndex, pos - 1, n, nodeToIndex);
        root->right = solve(in, pre, index, pos + 1, endIndex, n, nodeToIndex);

        return root;
    }

    Node *buildTree(int in[], int pre[], int n) {
        int preIndex = 0;
        map<int, int> nodeToIndex;
        // create nodes to index mapping
        createMapping(in, nodeToIndex, n);
        Node *ans = solve(in, pre, preIndex, 0, n - 1, n, nodeToIndex);

        return ans;
    }
};
