Short Approach 📝

    Problem: Count the number of good nodes in a binary tree.
    Definition: A good node is a node whose value is greater than or equal to all previous nodes on the path from the root to that node.
    Idea:
    Use DFS traversal.
    At each node:
    If the node’s value ≥ maxval → count it as a good node.
    Update maxval to max(maxval, node->val).
    Recursively check left and right children.
    Traversal Order: Pre-order (Root → Left → Right).
      
    Time Complexity: O(n) → visit all nodes once.
    Space Complexity: O(h) → recursion stack, where h = tree height.


int goodNodes(TreeNode* root) {
    return dfs(root, root->val);                 // Start DFS with root's value as max
}

private:
int dfs(TreeNode* node, int maxval) {
    if (!node) return 0;                         // Base case: null node → no good nodes

    int res = (node->val >= maxval) ? 1 : 0;     // Check if current node is good
    maxval = max(maxval, node->val);             // Update max value seen so far

    res += dfs(node->left, maxval);              // Count good nodes in left subtree
    res += dfs(node->right, maxval);             // Count good nodes in right subtree

    return res;                                  // Return total good nodes from this branch
}
