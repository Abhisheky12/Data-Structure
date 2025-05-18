class Solution {
    
    // Helper function to find the maximum diagonal level `l`
    void find(Node* root, int pos, int &l) {
        if (!root) {
            return;
        }
        
        // Update max diagonal level
        l = max(pos, l);
        
        // Left child goes to next diagonal (pos + 1)
        find(root->left, pos + 1, l);
        
        // Right child stays on the same diagonal
        find(root->right, pos, l);
    }
    
    // Helper function to store nodes in corresponding diagonals
    void findDig(Node *root, int pos, vector<vector<int>>& ans) {
        if (!root) {
            return;
        }
        
        // Add current node's data to the diagonal `pos`
        ans[pos].push_back(root->data);
        
        // Left child goes to next diagonal
        findDig(root->left, pos + 1, ans);
        
        // Right child stays on the same diagonal
        findDig(root->right, pos, ans);
    }
    
public:
    vector<int> diagonal(Node *root) {
        int l = 0;  // Max number of diagonals
        
        // First, find how many diagonals we need
        find(root, 0, l);
        
        // Create a vector of vectors to hold all diagonal elements
        vector<vector<int>> ans(l + 1);
        
        // Fill the diagonals with node data
        findDig(root, 0, ans);
        
        // Flatten the result diagonals into a single output list
        vector<int> temp;
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                temp.push_back(ans[i][j]);
            }
        }
        return temp;
    }
};
