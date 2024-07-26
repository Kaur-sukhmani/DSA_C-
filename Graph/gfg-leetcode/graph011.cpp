// Number of Enclaves

// https://leetcode.com/problems/number-of-enclaves/description/
/*
 Number of Enclaves

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
*/

/*USING DFS*/
class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        
        int drow[4] = {-1, 1, 0, 0};
        int dcol[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int newRow = row + drow[k];
            int newCol = col + dcol[k];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol] && grid[newRow][newCol] == 1) {
                dfs(newRow, newCol, vis, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // SC->O(M*N)
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // Check the boundary rows and columns
        // TC->O(M)
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && grid[0][j] == 1) {
                dfs(0, j, vis, grid);
            }
            if (!vis[n-1][j] && grid[n-1][j] == 1) {
                dfs(n-1, j, vis, grid);
            }
        }
        // TC->O(N)
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && grid[i][0] == 1) {
                dfs(i, 0, vis, grid);
            }
            if (!vis[i][m-1] && grid[i][m-1] == 1) {
                dfs(i, m-1, vis, grid);
            }
        }
        // Count the number of enclaves
        // TC->O(M*N*4)
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};
// TC->O(M*N*4)
// SC->O(M*N)

/*USING BFS*/
#include <vector>
#include <queue>

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        
        // Check the boundary rows and columns and initialize BFS
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && grid[0][j] == 1) {
                q.push({0, j});
                vis[0][j] = 1;
            }
            if (!vis[n-1][j] && grid[n-1][j] == 1) {
                q.push({n-1, j});
                vis[n-1][j] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && grid[i][0] == 1) {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if (!vis[i][m-1] && grid[i][m-1] == 1) {
                q.push({i, m-1});
                vis[i][m-1] = 1;
            }
        }

        // BFS to mark all reachable '1's from the boundary
        int drow[4] = {-1, 1, 0, 0};
        int dcol[4] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int newRow = row + drow[k];
                int newCol = col + dcol[k];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol] && grid[newRow][newCol] == 1) {
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = 1;
                }
            }
        }
        
        // Count the number of enclaves
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }
     
        return count;
    }
};
