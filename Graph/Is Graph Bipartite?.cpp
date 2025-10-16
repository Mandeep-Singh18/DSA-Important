🧠 Short Approach
    Use DFS to color nodes with two colors (0 and 1).
    If a neighbor has the same color → graph is not bipartite.
    Check all components to handle disconnected graph.

⏱️ Time & Space Complexity
    Time: O(V + E) → visit all nodes and edges once.
    Space: O(V) → recursion stack + color array.

💡 In short:
    DFS with two-coloring → conflict? → not bipartite.

💻 Code (With Short Comments)
  
class Solution {
public:
    bool dfs(int node, int c, vector<int>& color, vector<vector<int>>& graph){
        color[node] = c;                     // color current node
        for(int neigh : graph[node]){
            if(color[neigh] == -1){          // unvisited neighbor
                if(!dfs(neigh, c^1, color, graph)) return false;
            } else if(color[neigh] == c){    // neighbor same color → conflict
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph){
        int n = graph.size();
        vector<int> color(n, -1);            // -1 = uncolored

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(!dfs(i, 0, color, graph)) return false;
            }
        }
        return true;
    }
};
