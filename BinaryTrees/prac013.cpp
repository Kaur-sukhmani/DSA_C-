// Bottom View of Binary Tree
// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
/*
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.

Note: The Input/Output format and Example given are used for the system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from the stdin/console. The task is to complete the function specified, and not to write the full code.
 
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        map<int, int>topNode; //horizontal distance ,node
        queue<pair<Node*,int>>q; //Node,horizontal distance 
        
        q.push(make_pair(root,0)); //first data isnserted
        while(!q.empty()){
            pair<Node*,int> temp=q.front();
            q.pop();
            Node* frontNode=temp.first;
            int hd=temp.second;
            
            if(topNode.find(hd)==topNode.end()){
                topNode[hd]=frontNode->data;
            }
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }
        for(auto i:topNode){
                ans.push_back(i.second);
            }
        return ans;
        
    }

};
