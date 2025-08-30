Short Approach 📝
    
    Problem: Find the Lowest Common Ancestor (LCA) of two nodes p and q in a Binary Search Tree (BST).
    Idea:
    In a BST, all left subtree nodes < root < all right subtree nodes.
    Traverse the tree:
    If both p & q > root → LCA is in the right subtree.
    If both p & q < root → LCA is in the left subtree.
    Otherwise, the current root is the LCA.
    Time Complexity: O(h) → worst case = height of tree.
    Space Complexity: O(1) → iterative approach, no recursion stack.


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
        if (p->val > root->val && q->val > root->val)   // Both nodes in right subtree
            root = root->right;
        else if (p->val < root->val && q->val < root->val) // Both nodes in left subtree
            root = root->left;
        else
            return root;    // Current root splits p & q → LCA found
    }
    return nullptr;         // If tree is empty or invalid input
}
