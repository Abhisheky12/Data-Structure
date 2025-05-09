class Solution {
    public:
      vector<int> largestValues(Node* root) {
          // code here
          queue<Node *>q;
          q.push(root);
          
          vector<int>ans;
          Node *temp;
          
          while(!q.empty()){
              
              int sizeofqueue=q.size();
              int largeatlevel=INT_MIN;
              for(int i=0;i<sizeofqueue;i++){
                    temp=q.front();
                    q.pop();
                    int largeatlevel=max(largeatlevel,temp->data);
                    
                       if(temp->left)
                       q.push(temp->left);
                       if(temp->right)
                       q.push(temp->right);
                         
              }
              ans.push_back(largeatlevel);
              
          }
          return ans;