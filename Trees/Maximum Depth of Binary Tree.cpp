Short Approach 📝
      Idea: The maximum depth of a binary tree = 1 + max(left subtree depth, right subtree depth).
      Method: Use recursion → find depths of left & right subtrees → take the maximum → add 1 for the current node.
      Time Complexity: O(n) → visit every node once.
      Space Complexity: O(h) → recursion stack, where h = tree height.

Code with Short Comments
int maxDepth(TreeNode* root) {
    if (!root) return 0;                    // Base case: empty tree → depth = 0

    int lh = maxDepth(root->left);          // Find depth of left subtree
    int rh = maxDepth(root->right);         // Find depth of right subtree

    return 1 + max(lh, rh);                 // Add 1 for current node & return max
}
