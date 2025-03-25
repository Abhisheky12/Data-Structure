

//by using array for storing element temporary
class Solution{
    public:
        stack<int> insertAtBottom(stack<int> st,int x){
           int s=st.size();
            vector<int>array(s);
                    int i=0;
            while(!st.empty()){
                array[i]=st.top();
                st.pop();
                i++;
            }
            int j=array.size()-1;
            st.push(x);
            while(j>=0){
                st.push(array[j]);
                j--;
            }
            return st;
        }
    };

    //by using stack for storing element temporary
    
//User function Template for C++

class Solution{
    public:
        stack<int> insertAtBottom(stack<int> st,int x){
            stack<int>temp;
            while(!st.empty()){
                temp.push(st.top());
                st.pop();
                
            }
            st.push(x);
            while(!temp.empty()){
                st.push(temp.top());
                temp.pop();
            }
            return st;
        }
    };