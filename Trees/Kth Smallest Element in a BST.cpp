Short Approach 📝

    Problem: Find the k-th smallest element in a Binary Search Tree (BST).
    Key Property of BST:
    In-order traversal of a BST → sorted order of node values.
    Idea:
    Perform in-order traversal (Left → Root → Right).
    Keep a counter while visiting nodes.
    When count == k, store the node’s value and stop traversal.
      
    Time Complexty: O(h + k)
    h = height of BST
    In the worst case, O(n) if tree is skewed.
    Space Complexity: O(h) → recursion stack for in-order traversal.


class Solution {
    int count = 0;                      // Counter for visited nodes
    int res;                            // Stores k-th smallest element

    void inorder(TreeNode* node, int k) {
        if (!node) return;              // Base case: null node → return

        inorder(node->left, k);         // Traverse left subtree first

        count++;                        // Increment counter for visited node
        if (count == k) {              // If k-th node found → store result
            res = node->val;
            return;
        }

        inorder(node->right, k);        // Traverse right subtree
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);               // Start in-order traversal
        return res;                     // Return k-th smallest value
    }
};
