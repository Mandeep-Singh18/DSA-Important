Approach:
    Backtracking + DFS to check if a word exists in the board.
    - For each cell, try to match the word starting from that position.
    - DFS explores all 4 directions (up, down, left, right).
    - Mark the cell as visited while exploring and unmark (backtrack) after.
    - Stop early if the whole word is matched.


int ROWS, COLS;
vector<vector<bool>> visited;

bool exist(vector<vector<char>>& board, string word) {
    ROWS = board.size();
    COLS = board[0].size();
    visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (dfs(board, word, r, c, 0)) {  // Try starting from each cell
                return true;
            }
        }
    }
    return false;
}

bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
    if (i == word.length()) return true;  // All chars matched

    // Out of bounds, mismatch, or already visited
    if (r < 0 || c < 0 || r >= ROWS || c >= COLS ||
        board[r][c] != word[i] || visited[r][c]) {
        return false;
    }

    visited[r][c] = true;  // Mark current cell visited

    // Explore in all 4 directions
    bool res = dfs(board, word, r + 1, c, i + 1) ||
               dfs(board, word, r - 1, c, i + 1) ||
               dfs(board, word, r, c + 1, i + 1) ||
               dfs(board, word, r, c - 1, i + 1);

    visited[r][c] = false; // Backtrack: unmark cell
    return res;
}
