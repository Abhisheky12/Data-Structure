#include <bits/stdc++.h> 

class Node{
    public:
    int index;
    Node *next;

    Node(int x){
        index=x;
        next=NULL;
    }
};
class NStack
{
public:
    stack<int>st;//to store empty index of original array
    int *arr;//original array
    Node **Top;//to store top elements  index of particular stack;
    NStack(int N, int S)
    {
        arr=new int[S];
        Top=new Node*[N];
        for(int i=0;i<N;i++){//initial make all index NULL
            Top[i]=NULL;
        }
        for(int i=0;i<S;i++){//pusing all indexes of original arrfay into stack beacuse initially all are empty
           st.push(i);
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(st.empty()){
            return 0;
        }
        arr[st.top()]=x;//pushing at top index in stack
        Node *temp=new Node(st.top());
        temp->next=Top[m-1];
        Top[m-1]=temp;
        st.pop();
        return 1;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(Top[m-1]==NULL){//agar stack empty hoga means kisi node ko nahi point kar raha yani ki stack me value hi nahi store hai koi
            return -1;
        }
        int element=arr[Top[m-1]->index];
        st.push(Top[m-1]->index);
        Top[m-1]=Top[m-1]->next;//deleting top node 
        return element;
       
    }
};