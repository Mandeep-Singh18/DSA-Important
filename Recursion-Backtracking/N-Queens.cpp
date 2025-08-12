
Approach:
    Use backtracking to place queens row-by-row.
    - For each row, try placing a queen in each column.
    - Before placing, check if column and both diagonals are safe.
    - If safe, place queen, recurse to next row, then backtrack.
    - Base case: all rows filled → store current board configuration.


vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;                   // Stores all solutions
    vector<string> board(n, string(n, '.'));      // Initialize empty board
    backtrack(0, board, res);
    return res;
}

void backtrack(int r, vector<string>& board, vector<vector<string>>& res) {
    if (r == board.size()) {                      // All queens placed
        res.push_back(board);
        return;
    }
    for (int c = 0; c < board.size(); c++) {
        if (isSafe(r, c, board)) {                 // Check safety before placing
            board[r][c] = 'Q';                     // Place queen
            backtrack(r + 1, board, res);          // Recurse to next row
            board[r][c] = '.';                     // Backtrack
        }
    }
}

bool isSafe(int r, int c, vector<string>& board) {
    // Check column
    for (int i = r - 1; i >= 0; i--)
        if (board[i][c] == 'Q') return false;

    // Check upper-left diagonal
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;

    // Check upper-right diagonal
    for (int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++)
        if (board[i][j] == 'Q') return false;

    return true;                                  // Safe to place
}
