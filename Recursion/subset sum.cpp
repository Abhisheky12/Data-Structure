#include<iostream>
using namespace std;
#include <vector>
void subsequence(int arr[],int index,int n,int sum,vector<int>&ans){
    if(index==n){
        ans.push_back(sum);
        // cout<<sum<<endl;
        return;
    }
    subsequence(arr,index+1,n,sum,ans);
     sum=sum+arr[index];
    subsequence(arr,index+1,n,sum,ans);
    
}
int main() {
      int arr[]={3,4,5};
     vector<int>ans;
      int sum=0;
      subsequence(arr,0,3,sum,ans);
      for(int i=0;i<ans.size();i++){
          cout<<ans[i]<<endl;
      }
    return 0;
}