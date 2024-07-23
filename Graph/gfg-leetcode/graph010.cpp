// Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/description/

/*Surrounded Regions

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]
*/
class Solution {
public:
// TC->O(N*M*4)

    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& mat) {
        vis[row][col] = 1;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, -1, 0, +1};
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, mat);
            }
        }
    }

    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

// TC->O(N)
        // Traverse first row and last row
        for (int j = 0; j < m; j++) {
            // For the first row
            if (!vis[0][j] && mat[0][j] == 'O') {
                dfs(0, j, vis, mat);
            }
            // For the last row
            if (!vis[n - 1][j] && mat[n - 1][j] == 'O') {
                dfs(n - 1, j, vis, mat);
            }
        }
// TC->O(M)
        // Traverse first col and last col
        for (int i = 0; i < n; i++) {
            // First col
            if (!vis[i][0] && mat[i][0] == 'O') {
                dfs(i, 0, vis, mat);
            }
            // Last col
            if (!vis[i][m - 1] && mat[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, mat);
            }
        }
// TC->O(N*M)
        // Flip the remaining 'O's to 'X's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }
    }
};
// SC->O(N*M)
// TC->O(N*M)
