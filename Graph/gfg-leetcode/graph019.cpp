/*
Directed Graph Cycle (using Kahns algo)
https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:



Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:

Input:


Output: 0
Explanation: no cycle in the graph

Your task:
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list adj as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.
In the adjacency list adj, element adj[i][j] represents an edge from i to j.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
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
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> ans=topoSort(V,adj);
        if(ans.size()==V){
            return 0; //if toposort ie all elements sorted then it is and Acyclic graph since it is DAG
        }
        return 1; //if the present elements are less than the element present then return true ;
        
    }
};
// if toposort ie all elements sorted then it is and Acyclic graph since it is DAG
//if the present elements are less than the element present then return true 
// since toposort works only in DAG and not in the cyclcic
