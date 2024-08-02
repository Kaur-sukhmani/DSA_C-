/*
207. Course Schedule
https://leetcode.com/problems/course-schedule/description/
https://www.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
        
        // Construct adjacency list
        for(auto pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            adj[prerequisite].push_back(course);
        }
        
        vector<int> ans = topoSort(n, adj);
        
        // If the topological sort includes all courses, it means no cycle exists
        if(ans.size() == n) {
            return true;
        }
        
        return false;
    }
};
