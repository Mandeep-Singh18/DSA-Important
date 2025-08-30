Short Approach 📝

      Idea:
      The diameter of a binary tree = the longest path between any two nodes, which can pass through the root or lie entirely in the left/right subtree.
      Method:
      Use post-order traversal to calculate the depth of each subtree.
      At every node, update the diameter as max(diameter, leftHeight + rightHeight).
      Return 1 + max(leftHeight, rightHeight) as the height for recursion.
      Time Complexity: O(n) → every node visited once.
      Space Complexity: O(h) → recursion stack, where h = tree height.


int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;                         // Stores the maximum diameter
    maxDepth(root, diameter);                 // Helper function to calculate diameter
    return diameter;                          // Return final diameter
}

int maxDepth(TreeNode* root, int& d) {
    if (!root) return 0;                      // Base case: empty tree → depth = 0

    int lh = maxDepth(root->left, d);         // Get left subtree depth
    int rh = maxDepth(root->right, d);        // Get right subtree depth

    d = max(d, lh + rh);                      // Update diameter if longer path found

    return 1 + max(lh, rh);                   // Return height of current node
}
