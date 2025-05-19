TreeNode* pruneTree(TreeNode* root) {
    if (root == NULL) return NULL;

    // First prune left and right children (bottom-up)
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);

    // If current node is 0 and both left and right are NULL => remove it
    if (root->val == 0 && root->left == NULL && root->right == NULL) {
        return NULL;
    }

    // Else keep the node
    return root;
}
