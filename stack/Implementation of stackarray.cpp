#include <iostream>
using namespace std;

class stack{
    int *arr;
    int size;
    int top;
    
    public:
    stack(int s){
        size=s;
        top=-1;
        arr=new int[s];
    }
    //push
    void push(int value){
        if(top==size-1){
            cout<<"stack overflow";
        }
        else{
            top++;
            arr[top]=value;  
            cout<<"Push"<<value<<"into stack\n";
        }
    }
    //pop
    void pop(){
        
        if(top==-1){
            cout<<"stack underflow";
        }
        else{
         int deleted=arr[top];
        top--;
        cout<<"pop"<<deleted<<"from stack\n";
        }
    }
    //peek
    int peek(){
        if(top==-1){
            cout<<"stack is empty";
            return -1;
        }
        else{
            return arr[top];
        }
    }
    //isempty
    int isempty(){
        if(top==-1){
            return 0;
        }
        else{
            return 1;
        }
    }
    //issize
    int issize(){
        return top+1;
    }
    
};
int main() {
    stack S(5);
    S.push(1);
    S.push(2);
    S.push(3);
    S.pop();
    cout<<S.peek()<<endl;
    cout<<S.isempty()<<endl;
    cout<<S.issize();
    

    return 0;
}