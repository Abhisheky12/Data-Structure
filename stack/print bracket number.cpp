class Solution {
    public:
  
      vector<int> bracketNumbers(string str) {
          // Your code goes here
          stack<int>st;
          int count=0;
          vector<int>temp;
          for(int i=0;i<str.size();i++){
              if(str[i]=='('){
      
                  count++;
                  st.push(count);
                  temp.push_back(count);
                  
              }
              else if(str[i]==')'){
                      temp.push_back(st.top());
                      st.pop();
                      
                  
              }
          }
          return temp;
      }
  };