




//type1
input>root[] = [10, 20, 30, 40, 50]  output> [[10], [20, 30], [40, 50]]   
class Solution {
    public:
      vector<vector<int>> levelOrder(Node *root) {
          vector<vector<int>> final;
          if (root == nullptr) return final;
          
          queue<Node*> q;
          q.push(root);
  
          while (!q.empty()) {
              int levelSize = q.size();  // Number of nodes at current level
              vector<int> currentLevel;
              
              for (int i = 0; i < levelSize; ++i) {
                  Node* temp = q.front();
                  q.pop();
                  currentLevel.push_back(temp->data);
  
                  if (temp->left) {
                      q.push(temp->left);
                  }
                  if (temp->right) {
                      q.push(temp->right);
                  }
              }
  
              final.push_back(currentLevel);  // Add the current level to final answer
          }
  
          return final;
      }
  };

//type2
 input> root[] = [10, 20, 30, 40, 50]  output> [10, 20, 30, 40, 50] 
  class Solution {
    public:
      vector<vector<int>> levelOrder(Node *root) {
         queue<Node *>q;
         q.push(root);
         
         vector<int>ans;
         
         Node* temp;
         while(!q.empty()){
             temp=q.front();
             q.pop();
             ans.push_back(temp->data);
           
             if(temp->left){
                 q.push(temp->left);
             }
             if(temp->right){
                 q.push(temp->right);
             }
         }
         return ans;
          
          
      }
  };
  