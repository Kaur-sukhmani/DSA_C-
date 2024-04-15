// Vertical Order Traversal of a Binary Tree
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
*/
/*Intuition and Approach
The intuition behind vertical traversal is to maintain the order of nodes based on their horizontal and vertical positions in the tree.

We can use a map to store nodes at each vertical level (x). Within each vertical level, a nested map is used to store nodes based on their horizontal position (y).

A multiset is used to maintain a sorted order of node values within each position. Perform a Breadth-First Search (BFS) traversal of the binary tree.

The queue (q) is initialized with the root node and its coordinates (x, y) representing the vertical and horizontal positions.

During each iteration of BFS, a node is dequeued, and its coordinates and value are extracted. The node's value is inserted into the corresponding position in the map.

If the current node has a left child, enqueue with updated coordinates ({x-1, y+1}).
If the current node has a right child, enqueue with updated coordinates ({x+1, y+1}).

After completing the BFS traversal, the map is used to construct the final resultresultresult. Iterate over the map, and for each vertical level (p.second), extract the values from the multiset and append them to a vector (colcolcol).

Append each vector (colcolcol) to the result vector (ansansans).

The approach ensures that nodes at the same vertical level are grouped together and sorted by their horizontal positions. The use of multisets guarantees a sorted order of node values within each vertical level. The result is a structured representation of the nodes' positions in the binary tree, organized by their vertical and horizontal coordinates.
*/
/*
Complexity
Time complexity: O(N*logN)
-- where N is the number of nodes in the binary tree.
Space complexity: O(N)
-- where N is the number of nodes in the binary tree.

*/
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p= q.front();
            q.pop();
            TreeNode* node= p.first;
            int x= p.second.first;
            int y= p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto p: nodes){
            vector<int> col;
            for(auto qu: p.second){
                col.insert(col.end(),qu.second.begin(),qu.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
