🧠 Short Approach
    Use Union-Find (Disjoint Set) with path compression and union by rank.
    For each edge, if both nodes are already in the same set → cycle → return edge.
    Otherwise, union the sets.

⏱️ Time & Space Complexity
    Time: O(N α(N)) → α(N) is inverse Ackermann function (nearly constant).
    Space: O(N) → for parent and rank arrays.

💡 In short:
  Union-Find detects the first edge creating a cycle → that’s the redundant connection.

💻 Code (With Short Comments)
  
class Solution {
    vector<int> parent, rank;

    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]); // Path compression
        return parent[i];
    }

    void join(int u, int v) {
        int rootU = find(u), rootV = find(v);
        if(rootU != rootV){
            // Union by rank
            if(rank[rootU] > rank[rootV]) parent[rootV] = rootU;
            else if(rank[rootU] < rank[rootV]) parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1); rank.resize(n + 1, 0);

        for(int i = 1; i <= n; i++) parent[i] = i; // Initialize

        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            if(find(u) == find(v)) return edge; // Cycle detected
            join(u, v);                          // Union sets
        }

        return {}; // Should never reach here for valid input
    }
};
