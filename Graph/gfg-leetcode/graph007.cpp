// Undirected Graph Cycle using BFS
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
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detectCycle(vector<int> adj[],int vis[],int start){
        vis[start]=1;
        queue<pair<int,int>> q;
        q.push({start,-1});
        while(!q.empty()){
            int Node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjNode:adj[Node]){
                if(!vis[adjNode]){
                    vis[adjNode]=1;
                    q.push({adjNode,Node});
                }
                else if(parent!=adjNode){
                    // off the adjNode ka parent woh hai hi nhi toh matlab cycle detect hua hai
                    return true;
                }
            }
            
        }
         return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // here V is the nodes
        // A visited array and intiialzed all to the 0 
        int vis[V]={0};
        // for 0 base indexing 
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detectCycle(adj,vis,i)==true){
                    return true;//their is presence of cycle
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
