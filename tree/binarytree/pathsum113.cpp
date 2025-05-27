


// approch 1
class Solution {
        void fill(TreeNode* root,int sum, vector<int>&temp,vector<vector<int>>&result, int targetSum){
                   if(root==NULL){
                    return;
                   }

                   sum=sum+root->val;
                   temp.push_back(root->val);
                   //leaf node if only
                   if (!root->left && !root->right) {
                        if(sum==targetSum){
                            result.push_back(temp);
                        }
                        temp.pop_back();// backtrack before returning
                        return;
                   }
                   fill(root->left,sum,temp,result,targetSum);
                   fill(root->right,sum,temp,result,targetSum);

                     temp.pop_back();  // backtrack after both calls
        }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int>temp;
        vector<vector<int>>result;
        fill(root,sum,temp,result,targetSum);

        return result;
    }
};



// approach 2


class Solution {
        void fill(TreeNode* root,int sum, vector<int>temp,vector<vector<int>>&result, int targetSum){
                   if(root==NULL){
                    return;
                   }

                   sum=sum+root->val;
                   temp.push_back(root->val);
                   //leaf node if only
                   if (!root->left && !root->right) {
                        if(sum==targetSum){
                            result.push_back(temp);
                        }
                       
                        return;
                   }
                   fill(root->left,sum,temp,result,targetSum);
                   fill(root->right,sum,temp,result,targetSum);

                    
        }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int>temp;
        vector<vector<int>>result;
        fill(root,sum,temp,result,targetSum);

        return result;
    }
};