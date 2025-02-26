class Solution {
  public:
    int minChar(string& s) {
    //     // Write your code here
    // vector<int> ans(26, 0); 
    // string s1;
    // for (int i = 1; i < s.size(); i++) {
    //     ans[s[i] - 'a']++;
    // }
    // int start = 1;
    // while (start <=s.size()) { 
    //     if (ans[s[start] - 'a'] % 2 == 0) {
    //         start++;
    //     }
        
    //     else {
    //     s1 =s[start]+s1;
    //     ans[s[start] - 'a']++;
    //         start++;
    //     }
    // }
    // return s1.size();
    string rev=s;
    reverse(rev.begin(),rev.end());
    int size=s.size();
    s+='$'+rev;//to seperate initial and added string
    // s+=rev;
    
    //longest prefix suffix
    int n=s.size();
    vector<int>lps(n,0);
    int pre=0,suff=1;
    while(suff<n) {
        if(s[pre]==s[suff]){
            lps[suff]=pre+1;
            pre++,suff++;
        }
        else{
            if(pre==0){
                suff++;
            }
            else{
                pre=lps[pre-1];
            }
        }
    }
    return size- lps[n-1];
    

    }
};