🧠 Short Approach
    Perform DFS from both oceans (Pacific & Atlantic) borders.
    From each ocean, mark all cells reachable via non-decreasing height paths.
    The intersection of both reachable sets gives cells where water can flow to both oceans.

⏱️ Time & Space Complexity
    Time: O(M × N) → each cell visited up to twice.
    Space: O(M × N) → visited arrays + recursion stack.

💡 In short:
    Run DFS from both oceans → find cells reachable by both → return their coordinates.

💻 Code (With Short Comments)
  
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}}; // 4 directions

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(); n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));   // Pacific reach
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));  // Atlantic reach

        // DFS from Pacific borders
        for (int j = 0; j < n; j++) dfs(0, j, heights, pacific);   // Top row
        for (int i = 0; i < m; i++) dfs(i, 0, heights, pacific);   // Left col

        // DFS from Atlantic borders
        for (int j = 0; j < n; j++) dfs(m-1, j, heights, atlantic); // Bottom row
        for (int i = 0; i < m; i++) dfs(i, n-1, heights, atlantic); // Right col

        vector<vector<int>> result;
        // Collect cells reachable by both oceans
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])               // Common cells
                    result.push_back({i, j});
            }
        }
        return result;
    }

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        visited[i][j] = true; // Mark visited
        for (auto& d : directions) {
            int x = i + d[0], y = j + d[1];
            // Skip if out of bounds, already visited, or height decreases
            if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || heights[x][y] < heights[i][j])
                continue;
            dfs(x, y, heights, visited); // Explore next
        }
    }
};
