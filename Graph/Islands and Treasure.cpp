🧠 Approach (Multi-source BFS)
          This problem is a multi-source BFS variant of the “Walls and Gates” problem.
          Treat each gate (0) as a starting point.
          Perform BFS frm all gates simultaneously to fill the distance to the nearest gate for each empty room (INT_MAX).
          
          Each step from a gate increases the distance by +1.
          ⏱️ Complexity
          Time Complexity: O(M × N) — each cell visited once.
          Space Complexity: O(M × N) — queue and auxiliary structures.
          
          ✅ In short:
          Start BFS from all gates (0) → spread distances → each empty cell (INT_MAX) gets filled with shortest distance to nearest gate.

💻 Code (With Short Comments)

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        // Push all gates (0) into queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    q.push({i, j});
            }
        }

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 4 directions

        // BFS from all gates
        while (!q.empty()) {
            auto [row, col] = q.front(); q.pop();

            for (auto& d : dirs) {
                int r = row + d[0], c = col + d[1];

                // Skip if out of bounds or already visited
                if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != INT_MAX)
                    continue;

                grid[r][c] = grid[row][col] + 1; // Update distance
                q.push({r, c}); // Add next cell
            }
        }
    }
};
