/*
Directed Graph Cycle Using DFS
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
    // Function to detect cycle in a directed graph.
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<int> adj[]) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, vis, pathVis, adj)) {
                    return true;
                }
            } else if (pathVis[it]) {
                return true;
            }
        }
        pathVis[node] = 0; // Unmark the node in path visited array before returning
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis, adj)) {
                    return true;
                }
            }
        }
        return false;
    }
};


/*Using single visited array*/
public static boolean dfs(int src, int[] visited, ArrayList<ArrayList<Integer>> adj)
    {
        //Mark the node as visited
        visited[src] = 2;
        
        for(int nbr : adj.get(src))
        {
            //If unvisited
            if(visited[nbr] == 0)
            {
                //Mark it as same path
                visited[nbr] = 2;
                if(dfs(nbr,visited,adj) == true)
                {
                    return true;
                }
            }
            else if(visited[nbr] == 2)
            {
                return true;
            }
        }
        
        //Backtrack to visited
        visited[src] = 1;
        return false;
        
    }
    public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
        // code here
       
        //Space optimization using only visited array
     
        int[] visited = new int[V];
        Arrays.fill(visited, 0);
        
        
        /* 
        0 - Unvisited
        1 - Visited
        2 - Same Path
        */
       
    
        for(int i = 0 ; i < V ; i++)
        {
            if(visited[i] == 0)
            {
                if(dfs(i,visited,adj) == true)
                {
                    return true;
                }
            }
        }
        return false;
        
    }
}
