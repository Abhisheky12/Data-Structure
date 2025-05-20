class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        // Morris Traversal starts
        while (root) {
            // Case 1: If left child is null, visit this node and go to right
            if (root->left == NULL) {
                ans.push_back(root->val);  // Add current node's value to result
                root = root->right;        // Move to right child
            } 
            else {
                // Find the inorder predecessor of current node
                TreeNode* curr = root->left;
                while (curr->right && curr->right != root) {
                    curr = curr->right;
                }

                // Case 2: Make a thread (temporary link) from predecessor to current node
                if (curr->right == NULL) {
                    curr->right = root;    // Create temporary link
                    root = root->left;     // Move to left child
                }
                // Case 3: Thread already exists - means left subtree is done
                else {
                    curr->right = NULL;    // Remove the temporary link
                    ans.push_back(root->val);  // Visit current node
                    root = root->right;    // Move to right child
                }
            }
        }
        return ans;
    }
};
