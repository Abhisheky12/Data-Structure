vector<int> makeBeautiful(vector<int> arr) {
    // code here
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        if(st.empty()){
            st.push(arr[i]);
        }
        else{
            if((arr[i]<0 &&st.top()<0) || (arr[i]>=0 &&st.top()>=0)){
                st.push(arr[i]);
            }
            else{
                st.pop();
            }
        }
    }
    vector<int>temp(st.size());
    int j=st.size()-1;
    while(!st.empty()){
        temp[j]=st.top();
        st.pop();
        j--;
    }
    return temp;
    
    
    
}