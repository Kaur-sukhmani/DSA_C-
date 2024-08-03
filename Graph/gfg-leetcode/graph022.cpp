/*
802. Find Eventual Safe States
https://leetcode.com/problems/find-eventual-safe-states/description/

There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

Example 1:

Illustration of graph
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4
*/
class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[])  
    {
        vector<int> ans;
        vector<int> indegree(V, 0); // Corrected the initialization of indegree array
        
        // Calculate indegree for each node
        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        // Initialize the queue with all nodes having indegree 0
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Process nodes in topological order
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            // Reduce indegree for all adjacent nodes
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return ans;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];  // Adjacency list for reversed graph
        
         // Reverse the graph using a simple for loop
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                int node = graph[i][j];
                adj[node].push_back(i);  // Reverse the edge direction
            }
        }
        // Perform topological sort on the reversed graph
        vector<int> topoSortedNodes = topoSort(n, adj);
        
        // The nodes with 0 indegree in the original graph are the safe nodes
        // Since we performed the topo sort on the reversed graph,
        // the nodes included in the topoSortedNodes are the safe nodes
        sort(topoSortedNodes.begin(), topoSortedNodes.end()); // Optional: Sort for a sorted output
        return topoSortedNodes;
    }
};
