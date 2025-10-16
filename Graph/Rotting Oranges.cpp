🧠 Approach (Multi-source BFS)
      Use BFS starting from all initially rotten oranges (2).
      At each minute (each BFS level), all adjacent fresh oranges (1) become rotten (2).
      Keep track of time (levels in BFS) and count of remaining fresh oranges.
      When BFS ends:
      If no fresh oranges remain → return minutes taken.
      Else → return -1 (some oranges couldn’t rot).

⏱️ Complexity
      Time Complexity: O(M × N) — each cell visited once.
      Space Complexity: O(M × N) — for queue and visited grid.

✅ In short:
      Perform multi-source BFS from all rotten oranges → each level = 1 minute → spread rotting until all fresh oranges are converted.

💻 Code (With Short Comments)
  
int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visited = grid;  // Copy of grid
    queue<pair<int, int>> q;             // Stores rotten oranges
    int countFreshOrange = 0;

    // Step 1: Fill queue with rotten oranges & count fresh ones
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 2)
                q.push({i, j});
            if (visited[i][j] == 1)
                countFreshOrange++;
        }
    }

    // No fresh orange → 0 mins | No rotten → impossible
    if (countFreshOrange == 0) return 0;
    if (q.empty()) return -1;

    int minutes = -1;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}}; // 4 directions

    // Step 2: BFS to spread rotting
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [x, y] = q.front(); q.pop();

            for (auto [dx, dy] : dirs) {
                int i = x + dx, j = y + dy;

                if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1) {
                    visited[i][j] = 2;  // Rot the fresh orange
                    countFreshOrange--;
                    q.push({i, j});
                }
            }
        }
        minutes++; // One level (minute) passed
    }

    // Step 3: Check if all oranges rotted
    return (countFreshOrange == 0) ? minutes : -1;
}
