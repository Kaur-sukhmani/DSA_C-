// Flood Fill

// https://leetcode.com/problems/flood-fill/description/
/*
 Flood Fill

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

 

Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.

*/
class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int color, int initial_col, vector<vector<int>>& vis) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            image[row][col] = color;

            // Four possible directions: right, left, down, up
            int dRow[] = {0, 0, 1, -1};
            int dCol[] = {1, -1, 0, 0};
            
            for (int i = 0; i < 4; ++i) {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && 
                    image[newRow][newCol] == initial_col && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial_col = image[sr][sc];
        if (initial_col == color) return image; // No need to proceed if the initial color is same as the new color
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        bfs(image, sr, sc, color, initial_col, vis);
        return image;
    }
};



// USing 2nd Approacj ->DFS
    void dfs(int row, int col, vector<vector<int>>& ans, const vector<vector<int>>&     image, int intColor, int newColor, int dRow[], int dCol[]) {
        int n = image.size();
        int m = image[0].size();
        ans[row][col] = newColor;
        for (int i = 0; i < 4; i++) {
            int nrow = row + dRow[i];
            int ncol = col + dCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == intColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, intColor, newColor, dRow, dCol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int intColor = image[sr][sc];
        if (intColor == color) {
            return image; // No need to fill if the color is already the same
        }
        vector<vector<int>> ans = image;
        int dRow[] = {-1, 0, +1, 0};
        int dCol[] = {0, +1, 0, -1};
        dfs(sr, sc, ans, image, intColor, color, dRow, dCol);
        return ans;
    }
};
