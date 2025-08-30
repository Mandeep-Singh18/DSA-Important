Short Approach 📝

    Problem: Check if a given binary tree is a valid Binary Search Tree (BST).
    BST Property:
    For every node:
    Left subtree nodes < root < Right subtree nodes
    Idea:
    Use DFS recursion with a valid range (minval, maxval).
    If any node violates the range → return false.
    Recursively validate left and right subtrees with updated ranges.
      
    Time Complexity: O(n) → visit all nodes once.
    Space Complexity: O(h) → recursion stack, where h = tree height.
    

bool isValidBST(TreeNode* root) {
    return isValidBST(root, LONG_MIN, LONG_MAX);      // Start DFS with full value range
}

bool isValidBST(TreeNode* root, long minval, long maxval) {
    if (root == NULL) return true;                    // Empty tree → valid BST

    // If current node violates BST property, return false
    if (root->val <= minval || root->val >= maxval) 
        return false;

    // Left subtree → values must be < current node
    // Right subtree → values must be > current node
    return isValidBST(root->left, minval, root->val) &&
           isValidBST(root->right, root->val, maxval);
}
