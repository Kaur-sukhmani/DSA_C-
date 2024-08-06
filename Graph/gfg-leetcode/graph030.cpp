/*Shortest Distance in a Binary Maze
https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze
// https://leetcode.com/problems/shortest-path-in-binary-matrix/
https://leetcode.com/problems/shortest-path-in-binary-matrix/

Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing. The destination cell should be 1.

Example 1:

Input:
grid[][] = {{1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 0, 1}}
source = {0, 1}
destination = {2, 2}
Output:
3
Explanation:
1 1 1 1
1 1 0 1
1 1 1 1
1 1 0 0
1 0 0 1
The highlighted part in the matrix denotes the 
shortest path from source to destination cell.
Example 2:

Input:
grid[][] = {{1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0},
            {1, 0, 1, 0, 1}}
source = {0, 0}
destination = {3, 4}
Output:
-1
Explanation:
The path is not possible between source and 
destination, hence return -1.
Your Task:

You don't need to read or print anything. Your task is to complete the function shortestPath() which takes the a 2D integer array grid, source cell and destination cell as an input parameters and returns the shortest distance between source and destination cell.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)
*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
       int n = grid.size();
        int m = grid[0].size();

        // If source or destination is not walkable, return -1
        if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
            return -1;

        // Directions for moving up, down, left, right
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, pair<int, int>>> q;

        int sourcer = source.first;
        int sourcec = source.second;
        dist[sourcer][sourcec] = 0;
        q.push({0, {sourcer, sourcec}});

        int destr = destination.first;
        int destc = destination.second;

        while (!q.empty()) {
            int d = q.front().first;
            int currRow = q.front().second.first;
            int currCol = q.front().second.second;
            q.pop();

            // If we reach the destination, return the distance
            if (currRow == destr && currCol == destc) {
                return dist[destr][destc];
            }

            // Explore the 4 possible directions
            for (int i = 0; i < 4; ++i) {
                int row = currRow + dr[i];
                int col = currCol + dc[i];

                // Check if the new position is within bounds and walkable
                if (row >= 0 && row < n && col >= 0 && col < m &&
                    grid[row][col] == 1 && dist[row][col] > d + 1) {
                    
                    dist[row][col] = d + 1;
                    q.push({d + 1, {row, col}});
                }
            }
        }

        // If destination is unreachable
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code 


/*LEETCODE SOL*/
/* Shortest Path in Binary Matrix
Solved
Medium
Topics
Companies
Hint
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1
*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return -1;

        // If start or end is blocked, no path exists
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        // If the grid is 1x1 and the only cell is 0, return 1
        if (n == 1 && grid[0][0] == 0) return 1;
        
        // Directions for moving in 8 possible directions
        int dr[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
        int dc[8] = {0, 0, -1, 1, -1, -1, 1, 1};


        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, pair<int, int>>> q;

        dist[0][0] = 1;  // Distance to itself is 1
        q.push({1, {0, 0}});
         while (!q.empty()) {
            int d = q.front().first;
            int currRow = q.front().second.first;
            int currCol = q.front().second.second;
            q.pop();

            // If we reach the destination, return the distance
            if (currRow == n-1 && currCol == n-1) {
                return dist[n-1][n-1];
            }

            // Explore the 8 possible directions
            for (int i = 0; i < 8; ++i) {
                int row = currRow + dr[i];
                int col = currCol + dc[i];

                // Check if the new position is within bounds and walkable
                if (row >= 0 && row < n && col >= 0 && col < n &&
                    grid[row][col] == 0 && dist[row][col] > d + 1) {
                    
                    dist[row][col] = d + 1;
                    q.push({d + 1, {row, col}});
                }
            }
        }

        // If destination is unreachable
        return -1;
    }
};
