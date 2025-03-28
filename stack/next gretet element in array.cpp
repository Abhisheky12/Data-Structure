class Solution {
    public:
      // Function to find the next greater element for each element of the array.
      vector<int> nextLargerElement(vector<int>& arr) {
           int n=arr.size();
          vector<int>temp(n,-1);
          stack<int>st;
          for(int i=0;i<n;i++){
              if(st.empty()){
                  st.push(i);
              }
              else{
                  while(!st.empty()&& arr[st.top()]<arr[i]){
                      temp[st.top()]=arr[i];
                      st.pop();
                  }
                  st.push(i);
              }
          }
          return temp;
      }
  };