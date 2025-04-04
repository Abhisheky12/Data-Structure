
// User function template for C++

class Solution {
    public:
      int celebrity(vector<vector<int> >& mat) {
          // code here
          int n = mat.size();
          stack<int> st;
          int row = 0, col = 0;
  
          // Push all candidates onto the stack
          for (int i = n - 1; i >= 0; i--) {
              st.push(i);
          }
  
          // Process the stack to find one potential celebrity
          while (st.size() > 1) {
              int first = st.top(); st.pop();
              int second = st.top(); st.pop();
              
               if (mat[first][second]) {  
                  st.push(second);  // first knows second → first is not a celebrity  
              } else {  
                  st.push(first);  // first does not know second → second is not a celebrity  
              }
          }
          if (st.empty()) return -1;
  
          int num = st.top();
          st.pop();
  
          // Check if num is actually a celebrity using row & column sum
          for (int i = 0; i < n; i++) {
              
              if (i != num) {  // Exclude self
          row += mat[num][i];
          col += mat[i][num];
      }
               // Sum of column (everyone should know num)
          }
  
          if (row == 0 && col == n - 1) {
              return num;  // Valid celebrity
          } else {
              return -1;  // No valid celebrity
          }
      }
  };