// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{
    public:
    Node *prev;
    int data;
    Node *next;
    Node(int value){
        data=value;
        prev=NULL;
        next=NULL;
    }
};

int main(){
    int arr[]={1,2,3,4,5};
    Node *head=NULL;
    for(int i=0;i<5;i++){
        //no node exist in linked list
        if(head==NULL){
            head=new Node(arr[i]);
        }
        else{
            Node *temp=new Node(arr[i]);
            temp->next=head;
            temp->prev=NULL;
            head->prev=temp;
            head=temp;
        }
    }
    int x=4;
    if(x==0){
        if(head==NULL){
            head=new Node(7);
        }
        else{
            Node *temp=new Node(7);
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
    }
    else{
        x--;
        Node *tail=head;
        while(x){
            tail=tail->next;
            x--;
        }
        //insert at end
        if(tail->next==NULL){
             Node *temp=new Node(7);
             temp->prev=tail;
             tail->next=temp;
        }
        //insert at middle
        else{
            Node *temp=new Node(7);
            temp->next=tail->next;
            tail->next=temp;
            temp->prev=tail;
        }
    }
    
    
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}