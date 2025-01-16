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
    if(head!=NULL){
        Node *temp=head;
        head=head->next;
        delete temp;
        //if one node only
        if(head!=NULL){
        head->prev=NULL;
        }
        
    }
  
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}





//
// 2nd logic

#include <iostream>
using namespace std;

class Node {
public:
    Node *prev;
    int data;
    Node *next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    Node *head = NULL;

    // Create the linked list from the array
    for (int i = 0; i < 1; i++) { // Loop runs only once
        if (head == NULL) {
            head = new Node(arr[i]);
        } else {
            Node *temp = new Node(arr[i]);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    // Delete the head node if there are multiple nodes
    if (head != NULL && head->next != NULL) {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    // Handle the case where there is only one node
    else if (head != NULL && head->next == NULL) {
        delete head;
        head = NULL;
    }

    // Print the remaining list
    if (head == NULL) {
        cout << "List is empty" << endl;
    } else {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    return 0;
}
