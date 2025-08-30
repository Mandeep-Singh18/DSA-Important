Approach

  Use DFS to explore each node.
  At each node, calculate:
  Maximum path from left subtree
  Maximum path from right subtree
  If any path is negative, ignore it → take max(0, …).
  Update the global maximum path sum at every node.
  Return the best single path going upwards.


class Solution {
public:
    int maxi = INT_MIN;  // Stores the overall maximum path sum

    int dfs(TreeNode* root) {
        if (!root) return 0;  // Base case: null node → path sum = 0

        // Get max path from left & right, ignore negatives by using max(0, ...)
        int left = max(0, dfs(root->left));    // Max sum from left subtree
        int right = max(0, dfs(root->right));  // Max sum from right subtree

        // Update global maximum considering the path through the current node
        maxi = max(maxi, root->val + left + right);

        // Return the best path including current node + one side
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);       // Start DFS from root
        return maxi;     // Return the maximum path sum found
    }
};
