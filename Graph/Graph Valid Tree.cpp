🧠 Short Approach
    A graph is a tree if it is connected and has no cycles
    Check:
    Number of edges ≤ n-1 (necessary for tree).
    Use DFS to detect cycles.
    Ensure all nodes are visited (connected).

⏱️ Time & Space Complexity
    Time: O(V + E)  visit all nodes and edges once.
    Space: O(V + E) → adjacency list + visited set + recursion stack.

💡 In short:
    Check edges ≤ n-1, DFS for cycles, and confirm all nodes visited → valid tree.

💻 Code (With Short Comments)

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n - 1) return false; // too many edges → cycle

        vector<vector<int>> adj(n);           // adjacency list
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_set<int> visit;
        if(!dfs(0, -1, visit, adj)) return false; // check cycles

        return visit.size() == n; // check connectivity
    }

private:
    bool dfs(int node, int parent, unordered_set<int>& visit, vector<vector<int>>& adj){
        if(visit.count(node)) return false; // cycle detected
        visit.insert(node);

        for(int nei : adj[node]){
            if(nei == parent) continue;     // ignore parent
            if(!dfs(nei, node, visit, adj)) return false;
        }
        return true;
    }
};
