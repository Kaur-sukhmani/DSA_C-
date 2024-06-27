// Morris Traversal -> level order traversal without using stack anf recursive call
// https://leetcode.com/problems/binary-tree-inorder-traversal/
//https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree tNode has data, a pointer to left child
   and a pointer to right child */
struct tNode {
    int data;
    struct tNode* left;
    struct tNode* right;
};

struct tNode* newtNode(int data)
{
    struct tNode* node = new tNode;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
void MorrisTraversal(struct tNode* root)
{
    tNode *current,*pre;
    if(root==NULL){
        return ;
    }
    current=root;
    while(current!=NULL){
        if(current->left==NULL){
            cout<<current->data<<endl;
            current=current->right;
        }
        else{
            pre=current->left;
            while(pre->right!=NULL && pre->right!=current){
                pre=pre->right;
            }
            if(pre->right==NULL){
                cout<<current->data<<endl;
                pre->right=current;
            }
            else{
                pre->right=NULL;
                current=current->left;
            }/* End of if condition pre->right == NULL */
        }/* End of if condition current->left == NULL*/
    } /* End of while */
}

/* Driver program to test above functions*/
int main()
{
 
    /* Constructed binary tree is
            1
          /   \
         2     3
       /   \
      4     5
  */
    struct tNode* root = newtNode(1);
    root->left = newtNode(2);
    root->right = newtNode(3);
    root->left->left = newtNode(4);
    root->left->right = newtNode(5);
 
    MorrisTraversal(root);
 
    return 0;
}
