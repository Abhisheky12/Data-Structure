
//m1 using queue


// Helper function to determine the leftmost and rightmost horizontal distances (HD)
// from the root in the binary tree.
// 'indexes' starts from 0 for root, decreases for left child, increases for right child.
void find(Node *root, int indexes, int &l, int &r) {
    if (root == NULL) {
        return;
    }

    // Update minimum and maximum horizontal distances
    l = min(l, indexes); // farthest left
    r = max(r, indexes); // farthest right

    // Recursively go to left and right subtree with updated HD
    find(root->left, indexes - 1, l, r);
    find(root->right, indexes + 1, l, r);
}




class Solution {
  public:
    // Main function to return the top view of a binary tree
    vector<int> topView(Node *root) {
        // Initialize variables to store horizontal boundaries
        int l = 0, r = 0;

        // Step 1: Find the range of horizontal distances (l to r)
        find(root, 0, l, r);

        // Step 2: Initialize result and helper arrays
        // Size = r - l + 1 to cover all vertical lines from leftmost to rightmost
        vector<int> ans(r - l + 1);       // Stores the final top view nodes
        vector<int> filled(r - l + 1, 0); // Marks whether a vertical level is already filled

        // Step 3: Perform level order traversal (BFS)
        queue<Node*> q;       // Queue for tree nodes
        queue<int> index;     // Queue for their corresponding horizontal distances (HDs)

        // Start from root node at index 0, adjusted to positive by shifting with -l
        q.push(root);
        index.push(-l);       // So the leftmost HD maps to index 0 in vector

        while (!q.empty()) {
            Node* temp = q.front(); 
            q.pop();
            int pos = index.front(); 
            index.pop();

            // Step 4: If it's the first node at this horizontal level, record it
            if (!filled[pos]) {
                filled[pos] = 1;
                ans[pos] = temp->data;
            }

            // Step 5: Push left and right children with updated horizontal distances
            if (temp->left) {
                q.push(temp->left);
                index.push(pos - 1); // Move left in HD
            }

            if (temp->right) {
                q.push(temp->right);
                index.push(pos + 1); // Move right in HD
            }
        }

        // Step 6: Return the constructed top view
        return ans;
    }
};




//m2 using recursion
void find(Node *root,int indexes,int &l,int &r){
    if(root==NULL){
        return;
    }
    
    l=min(l,indexes);
    r=max(r,indexes);
    
    find(root->left, indexes-1,l,r);
    find(root->right, indexes+1,l,r);
    
    
    
}

void Tview(Node *root,int pos,vector<int>&ans,vector<int>&level,int l){
    
    
    if(!root)
    return;
    //jab current level ki valuekam hogi us leel se jo level[pos] pe hoga tab fill karenge 
    if(level[pos]>l){
        ans[pos]=root->data;
        level[pos]=l;
    }
    
    Tview(root->left,pos-1,ans,level,l+1);
    Tview(root->right,pos+1,ans,level,l+1);
    
}

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        int l=0,r=0;
        find(root,0,l,r);
        vector<int>ans(r-l+1);
        vector<int>level(r-l+1,INT_MAX);
        Tview(root,-l,ans,level,0);
       
        
        return ans;
    }
};