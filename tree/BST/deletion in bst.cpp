class Solution {
  public:
    // Function to delete a node from BST.
    Node *deleteNode(Node *root, int target) {
        // your code goes here
        if(!root){
            return NULL; 
        }
         
        if(root->data>target){
            root->left=deleteNode(root->left,target);
            return root;
         }
        else if(root->data<target){
            root->right=deleteNode(root->right,target);
            return root;
         }
        else
         {
            //leaf node
            if(!root->left &&! root->right){
                delete root;
                return NULL;
            }
            //1 child exist
            else if(root->right==NULL && root->left!=NULL){//right child exist

                  Node*temp=root->left;
                  delete root;
                  return temp;
            }
            else if(root->right!=NULL && root->left==NULL){//left child exist
            
                  Node*temp=root->right;
                  delete root;
                  return temp;
            }
            //2 child exist
            else{
                //find the greatest element from left
                 Node *child=root->left;
                 Node*parent=root;
                 
                 //right mpst node tak pauchana hai
                 while(child->right){
                     parent=child;
                     child=child->right;
                 }
                 if(root!=parent){
                     parent->right=child->left;
                     child->left=root->left;
                     child->right=root->right;
                     delete root;
                     return child;
                 }
                 else{
                       child->right=root->right;
                       delete root;
                       return child;
                 }
            }

         }
    }
};