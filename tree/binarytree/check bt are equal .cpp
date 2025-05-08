class Solution {
    public:
      // Function to check if two binary trees are identical
      bool isIdentical(Node *r1, Node *r2) {
          
          // Base case: If both nodes are NULL, trees are identical up to this branch
          if (r1 == NULL && r2 == NULL) {
              return true;
          }
  
          // If one is NULL and the other isn't, trees are not identical
          if ((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)) {
              return false;
          }
  
          // If the current node data doesn't match, trees are not identical
          if (r1->data != r2->data) {
              return false;
          }
  
          // Recursively check left subtrees and right subtrees
          return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
      }
  };
  