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
int main() {
    Node *Head;
    Head=NULL;
    int arr[]={2,4,6,10};
    
    for(int i=0;i<4;i++)
    {
    //Linked list not exist
    if(Head==NULL){
        Head=new Node(arr[i]);
      }
    //Linked list exist
    else{
        Node *temp;
        temp=new Node(arr[i]);
        temp->next=Head;
        Head=temp;
        //temp ka scope yahi block me hai 
       }
    }
    //print 
    Node *temp=Head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
    return 0;
}
