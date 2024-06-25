#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        root = new Node(d);
        return root;
    }
    if (d < root->data) {
        // Insert into the left subtree
        root->left = insertIntoBST(root->left, d);
    }
    else {
        // Insert into the right subtree
        root->right = insertIntoBST(root->right, d);
    }
    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void inOrder(Node* root){
    if(root==NULL){
        return ;
    }
    inOrder(root->left);
    cout<<root->data<<" "; // Print data in-order
    inOrder(root->right);
}

void preOrder(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" "; // Print data pre-order
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" "; // Print data post-order
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return; // Empty tree
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); // Get current level size for correct iteration

        for (int i = 0; i < levelSize; i++) { // Iterate over current level
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        cout << endl; // Print newline after each level
    }
}
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
Node* deleteFromBST(Node* root,int val){
    // base case
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        // 0 child 
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // 1 child 
        //  left child
        if(root->right==NULL && root->left!=NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        // right child 
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        // 2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini=findMin(root->right);
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }
    }
}
int main() {
    Node* root = NULL;
    cout << "Enter data to create BST (-1 to stop):" << endl;
    takeInput(root);

    cout << "Printing the BST in level order:" << endl;
    levelOrderTraversal(root);

    cout << "\nPrinting Inorder:" << endl;
    inOrder(root);
    
    cout << "\nPrinting PreOrder:" << endl;
    preOrder(root);

    cout << "\nPrinting PostOrder:" << endl;
    postOrder(root);

    cout<<"Min value is"<<findMin(root)<<endl;
    cout<<"Max value is"<<findMax(root)<<endl;

    // deletion 
    root=deleteFromBST(root,30);
    cout<<"printing the BST"<<endl;
    levelOrderTraversal(root);
    cout<<"printing inorder"<<endl;
    inOrder(root);

    cout<<endl<<"printing Preorder"<<endl;
    preOrder(root);

    cout<<endl<<"printing Postoder"<<endl;
    postOrder(root);

    return 0;
}
