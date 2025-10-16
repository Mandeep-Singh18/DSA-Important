🧠 Approach (DFS – Depth First Search)
        Traverse every cell in the grid.
        When you find land (1), perform DFS to explore the entire island and calculate its area (number of connected 1’s).
        During DFS, mark each visited cell as 0 (water) to avoid re-counting.
        Keep track of the maximum area found among all islands.
        
        ⏱️ Time & Space Comlexity
        Time Complexity: O(M × N) — each cell is visited once.
        Space Complexity: O(M × N) — recursion stack in worst case.


  
💻 Code (With Short Comments)
  
class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 4 directions
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int area = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) { // Found land
                    area = max(area, dfs(grid, r, c)); // Get island area
                }
            }
        }
        return area; // Max island area
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        // Base case: out of bounds or water
        if (r < 0 || c < 0 || r >= grid.size() ||
            c >= grid[0].size() || grid[r][c] == 0)
            return 0;

        grid[r][c] = 0; // Mark visited
        int res = 1;    // Current cell

        // Explore all 4 directions
        for (int i = 0; i < 4; i++)
            res += dfs(grid, r + directions[i][0],
                             c + directions[i][1]);
        return res; // Return area of island
    }
};
