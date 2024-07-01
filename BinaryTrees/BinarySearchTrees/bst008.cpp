// Flatten BST to sorted list
// https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/0
/*
You are given a Binary Search Tree (BST) with n nodes, each node has a distinct value assigned to it. The goal is to flatten the tree such that, the left child of each element points to nothing (NULL), and the right child points to the next element in the sorted list of elements of the BST (look at the examples for clarity). You must accomplish this without using any extra storage, except for recursive calls, which are allowed.

Note: If your BST does have a left child, then the system will print a -1 and will skip it, resulting in an incorrect solution.
*/

//{ Driver Code Starts
//Initial Template for C++

// } Driver Code Ends
//User function Template for C++

/* Node of the binary search tree 
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
   void inorder(Node* root, vector<int>& inorderVal)
    {
        if (root == NULL) return;

        if (root->left)
            inorder(root->left, inorderVal);

        inorderVal.push_back(root->data);

        if (root->right)
            inorder(root->right, inorderVal);
    }

    Node* flattenBST(Node* root)
    {
        vector<int> inorderVal;
        inorder(root, inorderVal);
        int n = inorderVal.size();

        if (n == 0) return NULL;

        Node* newnode = new Node(inorderVal[0]);
        Node* curr = newnode;

        for (int i = 1; i < n; i++)
        {
            Node* temp = new Node(inorderVal[i]);
            curr->left = NULL;
            curr->right = temp;
            // Update the current node
            curr = temp;
        }
        curr->left = NULL;
        curr->right = NULL;

        return newnode;
    }
};

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)


// Solution Using Morris Traversal 
// TC = O(n)

// SC = O(1)

Node *flattenBST(Node *root)
    {
        Node* curr = root;
        Node* prev = NULL;
        while(curr){
            if(curr->left){
                Node* pred = curr->left;
                while(pred->right) pred = pred->right;
                pred->right = curr;
                Node* temp = curr->left;
                curr->left = NULL;
                curr = temp;
            }else{
                if(prev){
                    prev->right = curr;
                }else{
                    root = curr;
                }
                prev = curr;
                curr = curr->right;
            }
        }
        return root;
    }
