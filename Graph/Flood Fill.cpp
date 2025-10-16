🧠 Short Approach
    Use DFS to traverse all connected cells with the same original color starting from (sr, sc).
    Replace each visited cell with the new color.

⏱️ Time & Space Complexity
    Time: O(N × M) → all cells may be visited once.
    Space: O(N × M) → recursion stack in worst case.

💡 In short:
    DFS from start cell → paint all connected same-color cells → return modified image.

💻 Code (With Short Comments)
  
class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(int r, int c, vector<vector<int>>& image, vector<vector<int>>& ans, int inColor, int color){
        ans[r][c] = color;                   // fill current cell
        int n = image.size(), m = image[0].size();

        for(int i=0; i<4; i++){
            int nr = r + dx[i], nc = c + dy[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && image[nr][nc]==inColor && ans[nr][nc]!=color){
                dfs(nr, nc, image, ans, inColor, color); // recurse
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
        int inColor = image[sr][sc];
        if(inColor == color) return image;   // no change needed

        vector<vector<int>> ans = image;
        dfs(sr, sc, image, ans, inColor, color);

        return ans;
    }
};
