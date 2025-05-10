class Solution {
    public:
      // Function to convert a binary tree into its mirror tree.
      void mirror(Node* root) {
          // Base case: If the current node is NULL, there's nothing to mirror
          if (root == NULL) {
              return;
          }
  
          // Swap the left and right children of the current node
          Node* temp = root->right;
          root->right = root->left;
          root->left = temp;
  
          // Recursively call mirror on the left and right subtrees
          mirror(root->left);
          mirror(root->right);
      }
  };
  