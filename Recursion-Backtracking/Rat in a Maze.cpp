
Approach:
  We explore all possible paths from (0,0) to (n-1,n-1) in a grid where:
    - 1 means open cell
    - 0 means blocked cell
  We can move in 4 directions: Down, Left, Right, Up.
  We use a visited matrix to avoid cycles.
  Whenever we reach the bottom-right corner, we store the current path.

Time complexity: O(4^(n*n)) in worst case (backtracking tries all paths)


void findPathHelper(int i, int j, vector<vector<int>>& a, int n,
                    vector<string>& ans, string move, vector<vector<int>>& vis) {
    // Base case: reached destination
    if (i == n - 1 && j == n - 1) {
        ans.push_back(move);
        return;
    }

    // Mark current cell as visited
    vis[i][j] = 1;

    // Move Down
    if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1)
        findPathHelper(i + 1, j, a, n, ans, move + 'D', vis);

    // Move Left
    if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1)
        findPathHelper(i, j - 1, a, n, ans, move + 'L', vis);

    // Move Right
    if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1)
        findPathHelper(i, j + 1, a, n, ans, move + 'R', vis);

    // Move Up
    if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1)
        findPathHelper(i - 1, j, a, n, ans, move + 'U', vis);

    // Backtrack: unmark current cell
    vis[i][j] = 0;
}

vector<string> findPath(vector<vector<int>>& m, int n) {
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));

    // Start only if source cell is open
    if (m[0][0] == 1)
        findPathHelper(0, 0, m, n, ans, "", vis);

    return ans;
}
