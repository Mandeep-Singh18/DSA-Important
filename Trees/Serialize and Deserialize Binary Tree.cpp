Short Approach 

    Serialize (Tree → String)
    Use Level Order Traversal (BFS) using a queue.
    node values to a string.
    If the node is NULL, append "#,".
    Return the final string.
    
    Deserialize (String → Tree)
    Use a queue to reconstruct the tree.
    Read values from the string using a stringstream.
    Create the root, then use BFS to attach left and right children.
    If the value is "#", mark it as NULL.


class Codec {
public:
    // Function to serialize the tree
    string serialize(TreeNode* root) {
        if (!root) return "";                        // If tree is empty
        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur == NULL) {
                s.append("#,");                      // Mark NULL nodes
            } else {
                s.append(to_string(cur->val) + ","); // Append value to string
                q.push(cur->left);                   // Push left child
                q.push(cur->right);                  // Push right child
            }
        }
        return s;                                   // Final serialized string
    }

    // Function to deserialize the string back into a tree
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;           // If string is empty

        stringstream s(data);
        string str;
        getline(s, str, ',');                        // Get root value
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            // Process left child
            getline(s, str, ',');
            if (str == "#") {
                cur->left = NULL;
            } else {
                TreeNode* left = new TreeNode(stoi(str));
                cur->left = left;
                q.push(left);
            }

            // Process right child
            getline(s, str, ',');
            if (str == "#") {
                cur->right = NULL;
            } else {
                TreeNode* right = new TreeNode(stoi(str));
                cur->right = right;
                q.push(right);
            }
        }
        return root;                                // Return reconstructed tree
    }
};
