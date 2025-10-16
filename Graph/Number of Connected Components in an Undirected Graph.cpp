🧠 Short Approach
    Build adjacency list.
    Use DFS to traverse unvisited nodes.
    Each DFS marks a connected component → increment count.

⏱️ Time & Space Complexity
    Time: O(V + E) → visit all nodes and edges once.
    Space: O(V + E) → adjacency list + visited array + recursion stack.

💡 In short:
    DFS from unvisited nodes → each DFS = 1 connected component → count them.

💻 Code (With Short Comments)
  
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);      // adjacency list
        vector<bool> visit(n, false);    // visited nodes

        // Build graph
        for (auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for(int node = 0; node < n; ++node){
            if(!visit[node]){
                dfs(adj, visit, node);   // visit all nodes in this component
                res++;                   // count component
            }
        }
        return res;
    }

private:
    void dfs(const vector<vector<int>>& adj, vector<bool>& visit, int node){
        visit[node] = true;
        for(int nei : adj[node]){
            if(!visit[nei])
                dfs(adj, visit, nei);   // visit neighbor
        }
    }
};
