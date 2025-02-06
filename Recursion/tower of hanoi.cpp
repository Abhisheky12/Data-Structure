 public: 
    // You need to complete this function
    void toh(int n,int from, int to, int aux){
        if(n==0){
            // cout<<"move disk"<<n<<"from rod"<<from<<"to rod"<<to;
            return;
        }
        toh(n-1,from,to,aux);
        //  cout<<"move disk "<<n<<"from rod "<<from<<"to rod "<<to;
         toh(n-1,aux,from,to);
        
    }

    int towerOfHanoi(int n, int from, int to, int aux) {
        toh(n,from,aux,to);
        return pow(2,n)-1;
    }
};