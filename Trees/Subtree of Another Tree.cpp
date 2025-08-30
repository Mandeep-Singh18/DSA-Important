Short Approach 📝

    Problem: Check if subRoot is a subtree of root.
    Idea:
    If both trees are identical, return true.
    Otherwise, recursively check left and right subtrees of root.
    Helper Function: sameTree() → checks if two trees are exactly the same.
      
    Time Complexity: O(m * n)
    n = nodes in root, m = nodes in subRoot.
    In the worst case, compare subRoot at each node in root.
    Space Complexity: O(h) → recursion stack, where h = height of root.


bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!subRoot) return true;                         // Empty tree is always a subtree
    if (!root) return false;                           // If root is null but subRoot isn't → false

    if (sameTree(root, subRoot)) return true;          // If both trees match → true

    // Otherwise, check in left or right subtree
    return isSubtree(root->left, subRoot) ||           
           isSubtree(root->right, subRoot);
}

bool sameTree(TreeNode* root, TreeNode* subRoot) {
    if (!root && !subRoot) return true;                // Both null → trees are identical

    if (root && subRoot && root->val == subRoot->val)  // If both nodes exist & values match
        return sameTree(root->left, subRoot->left) &&  // Recursively compare left subtrees
               sameTree(root->right, subRoot->right);  // Recursively compare right subtrees

    return false;                                      // Mismatch → not the same tree
}
