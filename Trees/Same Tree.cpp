Short Approach 📝

    Problem: Check if two binary trees p and q are identical.
    Idea:
    If both nodes are NULL → trees are identical at this point.
    If only one node is NULL → trees are different.
    Othewise, compare:
      Node values
      Left subtrees
      Right subtrees

Time Complexity: O(n) → visit all nodes once.
Space Complexity: O(h) → recursion stack, where h = tree height.

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL || q == NULL)            // If either node is NULL
        return p == q;                     // True if both are NULL, else false

    // Check current node's value + recursively check left & right subtrees
    return (p->val == q->val) &&           
           isSameTree(p->left, q->left) && 
           isSameTree(p->right, q->right);
}
