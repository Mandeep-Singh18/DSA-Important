🧠 Approach (DFS – Depth First Search)
      Traverse each cell in the grid.
      When a land cell '1' is found, start a DFS to mark all connected land cells as visited ('0').
      Each DFS call explores one complete island.
      Count the number of DFS calls — that’s the total number of islands.
  
⏱️ Time Complexity
    O(M × N) — Every cell is visited once.
    Space Complexity: O(M × N) (worst case recursion stack for all land cells).


  
class Solution {
private:
    int dy[4] = {1, -1, 0, 0}; // Directions for rows
    int dx[4] = {0, 0, -1, 1}; // Directions for cols
    int rows, cols;

    void dfs(vector<vector<char>>& grid, int r, int c) {
        // Base case: out of bounds or water
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0')
            return;

        grid[r][c] = '0'; // Mark visited

        for (int i = 0; i < 4; i++)
            dfs(grid, r + dy[i], c + dx[i]); // Explore neighbors
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int totalIslands = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') { // Found new island
                    dfs(grid, i, j);     // Mark all connected land
                    totalIslands++;      // Increment island count
                }
            }
        }
        return totalIslands;
    }
};
