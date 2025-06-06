public:
    void generate(int n,int left,int right, vector<string>&ans,string &temp){
        if(left+right==2*n){
            ans.push_back(temp);
            return;
        }
        if(left<n){
            temp.push_back('(');
            generate(n,left+1,right,ans,temp);
            temp.pop_back();
        }
        if(left>right){
            temp.push_back(')');
            generate(n,left,right+1,ans,temp);
            temp.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) { 
        vector<string>ans;
        string temp;
        generate(n,0,0,ans,temp);
        return ans;
    }
};