/*
Bipartite Graph using DFS
https://www.geeksforgeeks.org/problems/bipartite-graph/1
https://leetcode.com/problems/is-graph-bipartite/

Given an adjacency list of a graph adj of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.

Know more about Bipartite Graph: - https://www.geeksforgeeks.org/what-is-bipartite-graph/

Example 1:

Input: 

Output: 1
Explanation: The given graph can be colored 
in two colors so, it is a bipartite graph.
Example 2:

Input:

Output: 0
Explanation: The given graph cannot be colored 
in two colors such that color of adjacent 
vertices differs. 
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of the graph and returns a boolean value true if the graph is bipartite otherwise returns false.
 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

Constraints:
1 ≤ V, E ≤ 105
*/
//{ Driver Cod
class Solution {
public:
    // Using DFS
    bool dfs(int node, int col, vector<int> adj[], vector<int>& color) {
        color[node] = col;
        for (auto it : adj[node]) {
            if (color[it] == -1) {
                if (dfs(it, !col, adj, color) == false) 
                    return false;
            } else if (color[it] == col) {
                return false;
            }
        }
        return true;
    }

    // Using BFS (commented out)
    // bool check(int start, int V, vector<int> adj[], vector<int>& color) {
    //     queue<int> q;
    //     color[start] = 0;
    //     q.push(start);
    //     while (!q.empty()) {
    //         int node = q.front();
    //         q.pop();
    //         for (auto it : adj[node]) {
    //             // If the adjacent node is not yet colored, give it the opposite color
    //             if (color[it] == -1) {
    //                 color[it] = 1 - color[node];
    //                 q.push(it);
    //             }
    //             // If the adjacent node has the same color, return false
    //             else if (color[it] == color[node]) {
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, adj, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};
