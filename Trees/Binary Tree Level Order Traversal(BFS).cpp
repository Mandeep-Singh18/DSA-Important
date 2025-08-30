Short Approach 📝
    
    Problem: Return the level-order traversal (BFS) of a binary tree.
    Idea:
    Use a queue to process nodes level by level.
    At each level:
    Take the current queue size → number of nodes in that level.
    Pop all those nodes, store their values, and push their children into the queue.
    Store the current level in the final result.
    Traversal Type: Breadth-First Search (BFS).
    Time Complexity: O(n) → visit every node once.
    Space Complexity: O(n) → queue + result storage.


vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;                 // If tree is empty, return empty result

    queue<TreeNode*> q;
    q.push(root);                          // Start BFS from root

    while (!q.empty()) {
        int s = q.size();                  // Number of nodes in the current level
        vector<int> level;

        for (int i = 0; i < s; i++) {
            TreeNode* node = q.front();    // Get the current node
            q.pop();

            if (node->left) q.push(node->left);   // Push left child if exists
            if (node->right) q.push(node->right); // Push right child if exists

            level.push_back(node->val);    // Add current node value to level
        }
        ans.push_back(level);              // Store the entire level
    }
    return ans;                            // Return the final level order traversal
}
