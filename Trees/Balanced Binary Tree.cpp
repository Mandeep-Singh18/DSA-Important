Short Approach 📝
    Idea: A binary tree is balanced if, for every node:
    |leftHeight - rightHeight| ≤ 1 and both subtrees are balanced.
    Method:
    Use post-order traversal to calculate subtree heights.
    If at any point the height difference exceeds 1, return -1 immediately.
    If the helper function returns -1, the tree is not balanced.
    Time Complexity: O(n) → each node is visited once.
    Space Complexity: O(h) → recursion stack, where h = tree height.


bool isBalanced(TreeNode* root) {
    return maxDepth(root) != -1;              // If maxDepth returns -1 → unbalanced, else balanced
}

int maxDepth(TreeNode* root) {
    if (!root) return 0;                      // Base case: empty tree → height = 0

    int lh = maxDepth(root->left);            // Calculate left subtree height
    if (lh == -1) return -1;                  // If left subtree is unbalanced, propagate -1

    int rh = maxDepth(root->right);           // Calculate right subtree height
    if (rh == -1) return -1;                  // If right subtree is unbalanced, propagate -1

    if (abs(lh - rh) > 1) return -1;          // If current node unbalanced, return -1

    return 1 + max(lh, rh);                   // Otherwise, return current height
}
