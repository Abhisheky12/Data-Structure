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
    
   //delete last node
   
   if (Head != NULL) {
        if (Head->next == NULL) {
            delete Head;
            Head = NULL;
        } else {
            Node *curr = Head;
            Node *prev = NULL;
            while (curr->next != NULL) {
                prev = curr;
                curr = curr->next;
            }
            delete curr;
            prev->next = NULL;
        }
    }
     
     
     
    //print 
    Node *temp3=Head; 
    while(temp3!=NULL)
    {
        cout<<temp3->data<<" ";
        temp3=temp3->next;
    }
    
    return 0;
}
