  // Undirected Graph Cycle using DFS
// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
/*
Undirected Graph Cycle
Difficulty: MediumAccuracy: 30.13%Submissions: 423K+Points: 4
Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

Example 1:

Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
Output: 1
Explanation: 

1->2->3->4->1 is a cycle.
Example 2:

Input: 
V = 4, E = 2
adj = {{}, {2}, {1, 3}, {2}}
Output: 0
Explanation: 

No cycle in the graph.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.

NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.


*/
//{ Driver Code Starts
/*Apprach 2 USING DFS*/

    bool dfs(std::vector<int> adj[], int vis[], int node, int parent) {
        vis[node] = 1;
        for (auto adjNode : adj[node]) {
            if (vis[adjNode] == 0) {
                if (dfs(adj, vis, adjNode, node) == true)
                    return true;
            } else if (adjNode != parent) {
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, std::vector<int> adj[]) {
        int vis[V];
        std::fill(vis, vis + V, 0);
    
        // For 0 based indexing 
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(adj, vis, i, -1) == true)
                    return true;
            }
        }
        return false;
    }
SC->O(N)+O(N)
TC->O(N+2E)
