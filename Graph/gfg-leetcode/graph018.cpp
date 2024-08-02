// KAhns Algorithm
// Topological Sorting using BFS
// https://www.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort

/*
Topological sort
Difficulty: MediumAccuracy: 56.52%Submissions: 223K+Points: 4
Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find any valid topological sorting of the graph.

 

In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.

 

Example 1:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.
Example 2:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 4, 2, 1, 3, 0.
Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then the console output will be 1 else 0.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to return list containing vertices in Topological order. 
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
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/

  
// } Driver Code Ends


//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
