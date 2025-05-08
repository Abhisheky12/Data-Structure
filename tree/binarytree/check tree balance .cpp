class Solution {
    public:
    
      // Helper function to compute the height of the tree and check if it's balanced
      int height(Node *root, bool &valid) {
          // Base case: An empty tree has height 0
          if (root == NULL) {
              return 0;
          }
  
          // Recursively compute the height of left and right subtrees
          int l = height(root->left, valid);
          int r = height(root->right, valid);
  
          // If the difference in heights is more than 1, mark the tree as unbalanced
          // abs ensures we get the positive difference
          if (abs(l - r) > 1) {
              valid = 0; // Tree is not balanced
          }
  
          // Return the height of the current node
          return 1 + max(l, r);
      }
  
      // Main function to check if the tree is balanced
      bool isBalanced(Node* root) {
          bool valid = 1; // Assume tree is balanced initially
          height(root, valid); // Start recursive check
          return valid; // Return result
      }
  };
  