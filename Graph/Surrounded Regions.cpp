🧠 Short Approach
    Use DFS from boundary 'O' cells to mark all 'O's connected to the border (safe regions).
    Temporarily mark them as '#'.
    After DFS, convert remaining 'O's (trapped regions) to 'X' and revert '#' back to 'O'.

⏱️ Time & Space Complexity
    Time: O(M × N) → every cell visited at most once.
    Space: O(M × N) (recursion stack for DFS).

💡 In short:
    Mark border-connected 'O's as safe → flip the rest to 'X'.

💻 Code (With Short Comments)
  
void DFS(vector<vector<char>>& board, int i, int j, int m, int n) {
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') return; // Base
    board[i][j] = '#';                     // Mark safe region
    DFS(board, i-1, j, m, n);              // Up
    DFS(board, i+1, j, m, n);              // Down
    DFS(board, i, j-1, m, n);              // Left
    DFS(board, i, j+1, m, n);              // Right
}

void solve(vector<vector<char>>& board) {
    int m = board.size();
    if (m == 0) return;                    // Empty board check
    int n = board[0].size();

    // DFS from left & right borders
    for (int i = 0; i < m; i++) {
        if (board[i][0] == 'O') DFS(board, i, 0, m, n);
        if (board[i][n-1] == 'O') DFS(board, i, n-1, m, n);
    }

    // DFS from top & bottom borders
    for (int j = 0; j < n; j++) {
        if (board[0][j] == 'O') DFS(board, 0, j, m, n);
        if (board[m-1][j] == 'O') DFS(board, m-1, j, m, n);
    }

    // Convert trapped 'O' -> 'X' and safe '#' -> 'O'
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';  // Enclosed region
            if (board[i][j] == '#') board[i][j] = 'O';  // Restore safe region
        }
    }
}
