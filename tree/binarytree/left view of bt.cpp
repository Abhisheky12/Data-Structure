


//m1 using queue
class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<Node *>q;
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            
            for(int i=0;i<n;i++){
                Node *temp=q.front();
                q.pop();
                if(i==0){
                    ans.push_back(temp->data);
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};




//m2 using recursion
// Helper function to recursively compute the left view
void Lview(Node *root, int level, vector<int> &ans) {
    if (root == NULL) {
        return; // Base case: if node is null, simply return
    }

    // If this is the first node of its level, add it to the answer
    if (level == ans.size()) {
        ans.push_back(root->data);
    }

    // Recur for the left subtree first to ensure leftmost nodes are processed before right
    Lview(root->left, level + 1, ans);

    // Recur for the right subtree
    Lview(root->right, level + 1, ans);
}

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // This function initializes the required variables
        int level = 0;
        vector<int> ans;

        // Call the recursive helper function to fill the left view
        Lview(root, level, ans);

        // Return the collected left view
        return ans;
    }
};
