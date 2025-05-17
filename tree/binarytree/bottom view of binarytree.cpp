

//using queue
void find(Node *root,int indexes,int &l,int &r){
    if(root==NULL){
        return;
    }
    
    l=min(l,indexes);
    r=max(r,indexes);
    
    find(root->left, indexes-1,l,r);
    find(root->right, indexes+1,l,r);
    
    
    
}




class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
         // code here
       int l=0,r=0;
        find(root,0,l,r);
        vector<int>ans(r-l+1,0);
        // vector<bool>is(r-1+1,0);
        queue<Node*>q1;
        queue<int>ind;
        q1.push(root);
        ind.push(-1*l);
        while(!q1.empty()){
            Node* temp=q1.front();
            int pos=ind.front();
            q1.pop();
            ind.pop();
            
                ans[pos]=temp->data;
                
            if(temp->left){
            q1.push(temp->left);
            ind.push(pos-1);}
            if(temp->right){
            q1.push(temp->right);
            ind.push(pos+1);}
            
        }
        return ans; // Your Code Here
    
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

void Bview(Node *root,int pos,vector<int>&ans,vector<int>&level,int l){
    
    
    if(!root)
    return;
    //jab current level ki valuekam hogi us leel se jo level[pos] pe hoga tab fill karenge 
    if(level[pos]<l){
        ans[pos]=root->data;
        level[pos]=l;
    }
    
  
    Bview(root->right,pos+1,ans,level,l+1);
    Bview(root->left,pos-1,ans,level,l+1);
    
}


class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
         // code here
        int l=0,r=0;
        find(root,0,l,r);
        vector<int>ans(r-l+1);
        vector<int>level(r-l+1,INT_MIN);
        Bview(root,-l,ans,level,0);
       
        
        return ans;
    
    }
};