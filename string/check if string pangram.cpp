class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n=sentence.size();
        vector<int>alpha(26,0);
        for(int i=0;i<n;i++){
            int index=sentence[i]-'a';
            alpha[index]=1;
        }
        for(int i=0;i<alpha.size();i++){
            if(alpha[i]==0){
                return false;
            }
        }
        return true;
       
    }
};