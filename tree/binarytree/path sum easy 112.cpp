class Solution {
    bool Sum(TreeNode* root,int sum,int targetSum){

        if(root==NULL){
            return false;
        }

        sum += root->val;

        //if we reached leaf node 
        if(!root->left &&!root->right){    
            if(sum==targetSum){
              return true;
              }
            return false;
        }
       
        bool left=Sum(root->left,sum,targetSum);
        bool right=Sum(root->right,sum,targetSum);

        return left||right;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        

        int sum=0;
        bool result= Sum(root,sum,targetSum);
        return result;

    }
    
};