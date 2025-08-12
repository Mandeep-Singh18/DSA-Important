
Approach:
    Backtracking to fill empty cells ('.') with digits 1–9.
    - For each empty cell, try placing digits 1–9.
    - Check if placement is valid (row, col, 3x3 subgrid constraints).
    - If valid, place and recurse to solve next cell.
    - If a dead end is reached, backtrack and try the next digit.
    - Once all cells are filled, return true to stop recursion.


void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}

bool solve(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == '.') {                    // Empty cell found
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {        // Safe to place c
                        board[i][j] = c;                  // Place digit
                        if (solve(board)) return true;    // Continue solving
                        board[i][j] = '.';                // Backtrack
                    }
                }
                return false; // No valid digit fits here → backtrack
            }
        }
    }
    return true; // Board filled successfully
}

bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == c) return false;  // Check column
        if (board[row][i] == c) return false;  // Check row
        // Check 3x3 subgrid
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}
