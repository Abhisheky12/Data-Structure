class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
         if(root==NULL){
           return NULL;
         }
         else if(root->val>val){
            return searchBST(root->left,val);
         }
        else if(root->val<val){
            return searchBST(root->right,val);
         }
         else {
            return root;
         }
    }
};