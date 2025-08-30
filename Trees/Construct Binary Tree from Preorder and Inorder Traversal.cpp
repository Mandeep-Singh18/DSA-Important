Optimized One-Pass Approach 🚀
    Idea
    Use preorder → first element is always the root.
    rder to decide when to stop recursion instead of passing start and end indexes.
    Maintain a global preorder index and a global inorder index.
    Use recursion:
    If current inorder value matches the root, it means left subtree ends here, so move inIndex forward.
    Build left → then right subtree.


class Solution {
public:
    int preIndex = 0, inIndex = 0;
    unordered_map<int, int> inMap;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;
        return build(preorder, inorder, INT_MIN);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int stop) {
        if (preIndex >= preorder.size()) return nullptr;

        // If inorder element reached the stop value → subtree is done
        if (inIndex < inorder.size() && inorder[inIndex] == stop) {
            inIndex++;
            return nullptr;
        }

        // Create root node from preorder
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Recursively build left subtree until root is reached in inorder
        root->left = build(preorder, inorder, rootVal);

        // Then build right subtree
        root->right = build(preorder, inorder, stop);

        return root;
    }
};
