// Number of Provinces
// https://www.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces
// https://leetcode.com/problems/number-of-provinces/
/*
Number of Provinces
Difficulty: MediumAccuracy: 54.29%Submissions: 104K+Points: 4
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Example 1:

Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]

Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.
Example 2:
Input:
[
 [1, 1],
 [1, 1]
]

Output :
1

Your Task:  
You don't need to read input or print anything. Your task is to complete the function numProvinces() which takes an integer V and an adjacency matrix adj(as a 2d vector) as input and returns the number of provinces. adj[i][j] = 1, if nodes i and j are connected and adj[i][j] = 0, if not connected.

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int> adjList[], vector<int> &vis) {
        vis[node] = 1;
        // traversing neighbours
        for(auto it : adjList[node]) {
            if(!vis[it]) {
                vis[it] = 1;
                dfs(it, adjList, vis);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        // given adjacency matrix since for us it is comfortable 
        // to change adj matrix to adj list 
        vector<int> adjList[V];
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(adj[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(V, 0);
        int countProvinces = 0;
        for(int i = 0; i < V; i++) {
            if(vis[i] == 0) {
                dfs(i, adjList, vis);
                countProvinces++;
            }
        }
        
        return countProvinces;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends

//TIME COMPLEXITY->O(N)+O(V+E)
//SPACE COMPLEXITY -> O(N)+O(N)
