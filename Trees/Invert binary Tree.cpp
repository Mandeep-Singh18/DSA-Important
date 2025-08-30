Short Approach 📝
      Idea: Swap left and right children at each node.
      Method: Use recursion to invert the left and right subtrees, then return the root.
      Time Complexity: O(n) → every node visited once.
      Space Complexity: O(h) → recursion stack, where h = tree height.
      

TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;          // Base case: if tree is empty, return null

    swap(root->left, root->right);      // Swap left and right children

    invertTree(root->left);             // Recursively invert left subtree
    invertTree(root->right);            // Recursively invert right subtree

    return root;                        // Return the root after inversion
}
