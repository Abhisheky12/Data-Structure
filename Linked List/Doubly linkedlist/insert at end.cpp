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
        Node *prev=NULL;
        Node *next=NULL;
    }
};

int main(){
    int arr[]={1,2,3,4,5};
    Node *head=NULL;
    Node *tail=NULL;
    for(int i=0;i<5;i++){
        //no node exist in linked list
       
        if(head==NULL){
            head=new Node(arr[i]);
            tail=head;
            head->prev=NULL;
        }
        else{
            Node *temp=new Node(arr[i]);
            tail->next=temp;
            temp->prev=tail;
            // temp->next=NULL;
            tail=temp;;
            
        }
    }
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}