class Solution {
    
    // Function to add the left boundary nodes (excluding leaves)
    void LeftSub(Node *root, vector<int>& ans) {
        // Base case: if node is NULL or it's a leaf node, stop
        if (!root || (root->left == NULL && root->right == NULL)) {
            return;
        }
        // Add current node's data to answer (left boundary)
        ans.push_back(root->data);
        
        // Continue down the left subtree if exists, otherwise right subtree
        if (root->left)
            LeftSub(root->left, ans);
        else
            LeftSub(root->right, ans);
    }
    
    // Function to add all leaf nodes (from left to right)
    void Leaf(Node *root, vector<int>& ans) {
        if (!root) {
            return;
        }
        
        // If leaf node, add it to answer
        if (!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }
        // Recursively visit left and right subtrees for leaves
        Leaf(root->left, ans);
        Leaf(root->right, ans);
    }
    
    // Function to add right boundary nodes (excluding leaves), added in bottom-up order
    void RightSub(Node *root, vector<int>& ans) {
        // Base case: if node is NULL or leaf node, stop
        if (!root || (root->left == NULL && root->right == NULL)) {
            return;
        }
        
        // Recursively go down right subtree if exists, else left subtree
        if (root->right)
            RightSub(root->right, ans);
        else
            RightSub(root->left, ans);
        
        // Add current node's data after recursive call to get bottom-up order
        ans.push_back(root->data);
    }
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        
        if (!root) return ans;  // Handle empty tree
        
        // 1. Add root node first (root is always part of boundary)
        ans.push_back(root->data);
        
        // 2. If root is a leaf node (no children), return the result immediately
        if (root->left == NULL && root->right == NULL) {
            return ans;
        }
        
        // 3. Add left boundary nodes (excluding leaves)
        LeftSub(root->left, ans);
        
        // 4. Add all leaf nodes from left to right
        Leaf(root->left, ans);
        Leaf(root->right, ans);
        
        // 5. Add right boundary nodes (excluding leaves) in reverse order
        RightSub(root->right, ans);
        
        return ans;
    }
};
