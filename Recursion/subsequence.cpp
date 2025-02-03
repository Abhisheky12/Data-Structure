public:

    void subsequence(vector<int>& nums,int index,int n,vector<vector<int > >&ans,vector<int>temp){
    if(index==n){
        ans.push_back(temp);
        return;
    }
    subsequence(nums,index+1,n,ans,temp);
    temp.push_back(nums[index]);
    subsequence(nums,index+1,n,ans,temp);
    
}
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int> >ans;
      vector<int>temp;
      subsequence(nums,0,nums.size(),ans,temp);
      return ans;
    }
};



#include<iostream>
using namespace std;
#include <vector>
void subsequence(int arr[],int index,int n,vector<vector<int > >&ans,vector<int>temp){
    if(index==n){
        ans.push_back(temp);
        return;
    }
    subsequence(arr,index+1,n,ans,temp);
    temp.push_back(arr[index]);
    subsequence(arr,index+1,n,ans,temp);
    
}
int main() {
      int arr[]={1,2,3};
      vector<vector<int> >ans;
      vector<int>temp;
      subsequence(arr,0,3,ans,temp);
      for(int i=0;i<ans.size();i++){
        //   cout<<ans[i];
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j];
        }
        cout<<endl;
        
      }

    return 0;
}