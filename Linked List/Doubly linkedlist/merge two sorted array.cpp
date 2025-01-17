




/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Function to merge two sorted linked list.


//method1
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
          Node *head=new Node(0);
          Node *Tail=head;
          while(head1 && head2){
          
              if(head1->data <= head2->data){
                  Tail->next=head1;
                  head1=head1->next;
                  Tail=Tail->next;
                  Tail->next=NULL;
              }
              else{
                  Tail->next=head2;
                  head2=head2->next;
                  Tail=Tail->next;
                  Tail->next=NULL;
              }
           }
           if(head1!=NULL){
               Tail->next=head1;
           }
           else{
               Tail->next=head2;
           }
           Tail=head;
           head=head->next;
           delete Tail;
           return head;
    } 
};
//method2
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        //   Node *head=new Node(0);
         Node *head=NULL;
          Node *Tail=head;
          while(head1 && head2){
          
              if(head1->data <= head2->data){
                  if(head==NULL){
                      head=head1;
                      head1=head1->next;
                      Tail=head;
                      Tail->next=NULL;
                      
                  }
                  else{
                  Tail->next=head1;
                  head1=head1->next;
                  Tail=Tail->next;
                  Tail->next=NULL;
              }
              }
              else{
                   if(head==NULL){
                      head=head2;
                      head2=head2->next;
                      Tail=head;
                      Tail->next=NULL;
                      
                  }
                  else{
                  Tail->next=head2;
                  head2=head2->next;
                  Tail=Tail->next;
                  Tail->next=NULL;
              }
           }
          }
           if(head1!=NULL){
               Tail->next=head1;
           }
           else{
               Tail->next=head2;
           }
        //   Tail=head;
        //   head=head->next;
        //   delete Tail;
          return head;
    } 
};

