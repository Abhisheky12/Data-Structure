// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int value){
        data=value;
        next=NULL;
    }
};

Node* CreateLinkedList(int arr[],int index,int size){
    //Base case
    if(index==size)
    return NULL;
    
    Node *temp;
    temp=new Node(arr[index]);
    temp->next=CreateLinkedList(arr, index+1,size);
    return temp;
}

int main() {
    Node *Head;
    Head=NULL;
    int arr[]={2,4,6,10};
    
    Head=CreateLinkedList(arr,0,4);
    
    int x=3;//insert after this means after 6 and before 10
    int value=7;
    x--;
    Node *temp=Head;
    while(x){
        temp=temp->next;
        x--;
    }
    Node *temp2=new Node(value);
    temp2->next=temp->next;
    temp->next=temp2;
     
     
     
    //print 
    Node *temp3=Head; //declared above 36 line
    while(temp3!=NULL)
    {
        cout<<temp3->data<<" ";
        temp3=temp3->next;
    }
    
    return 0;
}
