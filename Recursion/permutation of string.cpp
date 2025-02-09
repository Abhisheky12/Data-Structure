// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<vector>
void permut(string &str,vector<string>&ans,string &temp,vector<bool>&visited){
    if(visited.size()==temp.size()){
        ans.push_back(temp);
        return;
    }
    
    
    for(int i=0;i<visited.size();i++){
        if(visited[i]==0){
            visited[i]=1;
            temp.push_back(str[i]);
             permut(str,ans,temp,visited);
             visited[i]=0;
             temp.pop_back();
        }
    }
}
int main() {
    // int arr[]={1,2,3};
    string str="abc";
    // vector<vector<int> >ans;
    vector<string>ans;
    // vector<int>temp;
    string temp;
    vector<bool>visited(3,0);
    permut(str,ans,temp,visited);
    for(int i=0;i<ans.size();i++){
        
         cout<<ans[i];
          cout<<endl;
    }
    

    return 0;
}