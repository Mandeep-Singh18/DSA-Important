Short Approach 📝

    Problem: Return the right side view of a binary tree → the nodes visible when viewed from the right.
    Idea:
    Use DFS (pre-order) but visit right subtree first.
    At each level, if the level equals the current size of the answer vector, it means this is the first node seen from the right, so we add it to the result.
    Traversal Order: Root → Right → Left
    Time Complexity: O(n) → visit every node once.
    Space Complexity: O(h) → recursion stack, where h = tree height.
  

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    rsview(root, 0, ans);                 // Start DFS from level 0
    return ans;                           // Return right view result
}

void rsview(TreeNode* root, int l, vector<int>& ans) {
    if (!root) return;                    // Base case: if node is null, return

    if (l == ans.size())                  // First node visited at this level → visible from right
        ans.push_back(root->val);

    rsview(root->right, l + 1, ans);      // Visit right subtree first
    rsview(root->left, l + 1, ans);       // Then visit left subtree
}
