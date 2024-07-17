// Sudoku Solver 
// https://leetcode.com/problems/sudoku-solver/description/
/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
*/
class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char val) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            // Row check
            if (board[row][i] == val) {
                return false;
            }
            // Column check
            if (board[i][col] == val) {
                return false;
            }
            // 3x3 subgrid check
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board.size();

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == '.') { // Empty cell
                    for (char val = '1'; val <= '9'; val++) {
                        if (isSafe(row, col, board, val)) {
                            board[row][col] = val;

                            // Proceed with the next cell
                            if (solve(board)) {
                                return true;
                            } else {
                                // Backtrack
                                board[row][col] = '.';
                            }
                        }
                    }
                    // If no number 1-9 can be placed in this cell, return false
                    return false;
                }
            }
        }
        // If no empty cell is left, the board is solved
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
