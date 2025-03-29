class Solution {
    public:
      vector<int> calculateSpan(vector<int>& arr) {
          int n=arr.size();
          stack<int>st;
          vector<int>temp(n,1);
          for(int i=n-1;i>=0;i--){
              while(!st.empty() && arr[st.top()]<arr[i]){
                  temp[st.top()]=st.top()-i;
                  st.pop();
              }
              st.push(i);
          }
          while(!st.empty()){
              temp[st.top()]=st.top()+1;
              st.pop();
          }
          return temp;
      }
  };