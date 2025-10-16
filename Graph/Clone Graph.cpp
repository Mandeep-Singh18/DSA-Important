🧠 Approach (DFS + Hash Map)
        Use DFS to traverse the graph starting from the given node.
        Use a map (oldToNew) to keep track of already-cloned nodes (to avoid infinite loops).
        For each node:
        If it’s not cloned yet → create a new copy and store it in the map.
        Recursively clone all its neighbors and add them to the new node’s neighbor list.
        Return the cloned version of the original node.
        
        ⏱️ Complexity
        Time Complexity: O(V + E) — visit each node and edge once.
        Space Complexity: O(V) — for map and recursion stack.
        
        ✅ In short:
        DFS clone + map for tracking → prevents cycles → clones every node and its edges exactly once.


💻 Code (With Short Comments)

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> oldToNew;       // Map original -> clone
        return dfs(node, oldToNew);
    }

    Node* dfs(Node* node, map<Node*, Node*>& oldToNew) {
        if (node == nullptr) return nullptr; // Base: empty graph

        if (oldToNew.count(node))            // Already cloned
            return oldToNew[node];

        Node* copy = new Node(node->val);    // Create clone
        oldToNew[node] = copy;               // Map it

        for (Node* nei : node->neighbors)    // Clone all neighbors
            copy->neighbors.push_back(dfs(nei, oldToNew));

        return copy;                         // Return cloned node
    }
};
