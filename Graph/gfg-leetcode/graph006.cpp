//  Rotting Oranges
// https://leetcode.com/problems/rotting-oranges/description/

/*


You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
*/
class Solution {
public:
    int bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        int minutes = 0;

        int dRow[] = {0, 0, 1, -1};
        int dCol[] = {1, -1, 0, 0};

        while (!q.empty()) {
            int size = q.size();
            bool rotten = false;

            for (int i = 0; i < size; ++i) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int j = 0; j < 4; ++j) {
                    int newRow = row + dRow[j];
                    int newCol = col + dCol[j];

                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                        grid[newRow][newCol] == 1 && !vis[newRow][newCol]) {
                        vis[newRow][newCol] = 1;
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        rotten = true;
                    }
                }
            }

            if (rotten) {
                ++minutes;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    return -1; // If there are still fresh oranges, return -1.
                }
            }
        }

        return minutes;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2 && !vis[i][j]) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        return bfs(grid, q, vis);
    }
};
