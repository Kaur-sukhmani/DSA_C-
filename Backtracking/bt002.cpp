// N Queen problem 
// https://leetcode.com/problems/n-queens/description/

// N-Queens
// Solved
// Hard
// Topics
// Companies
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]

class Solution {
public:
    vector<vector<string>> sols; // 2D vector of strings to store the solutions
    vector<vector<string>> solveNQueens(int n) {    
        vector<string> board(n, string(n, '.'));  // creating an empty board
        solve(board, 0); // calling the recursive function starting from the first column
        return sols; 
    }
    
    bool isSafe(vector<string>& board, int row, int col) {
        int n = size(board);
        for(int i = 0; i < n; i++) {
            // checking if there is a queen in the same row
            if(board[row][i] == 'Q') return false; 
            // checking if there is a queen in the same diagonal (top-left to bottom-right)
            if(row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
            if(row + i <  n && col - i >= 0 && board[row + i][col - i] == 'Q') return false;
            // checking if there is a queen in the same diagonal (bottom-left to top-right)
            if(row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') return false;
            if(row + i <  n && col + i <  n && board[row + i][col + i] == 'Q') return false;
        }
        return true;
    }
    
    // Recursive Function (solve) - It tries all possible placement of queen for the current column & recurses for the next column
    void solve(vector<string>& board, int col) {
        // Base condition. If we have placed queens in all columns, we have a solution
        if(col == size(board)) { 
            sols.push_back(board);
            return;
        }            
        // Try placing a queen on each row for a given column. 
        // Explore next column by placing Q at each valid row for the current column
        for(int row = 0; row < size(board); row++){
            if(isSafe(board, row, col)) {
                board[row][col] = 'Q';    // Queen placed on a valid cell
                solve(board, col + 1);    // Exploring next column
                board[row][col] = '.';    // Backtracking to get all possible solutions
            }
        }
    }
};


TC->O(N!)
SC->O(N*N)
