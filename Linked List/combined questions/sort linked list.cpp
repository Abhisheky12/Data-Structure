
//if replace ment of value of node is allowed

class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        Node *curr=head;
        int count0 = 0, count1 = 0, count2 = 0;
        while(curr){
            if(curr->data==0){
                count0++;
                curr=curr->next;
            }
            else if(curr->data==1){
                count1++;
                curr=curr->next;
            }
           else  if(curr->data==2){
                count2++;
                curr=curr->next;
            }
        }
        curr=head;
        while(count0){
            curr->data=0;
            curr=curr->next;
            count0--;
        }
         while(count1){
            curr->data=1;
            curr=curr->next;
            count1--;
        }
         while(count2){
            curr->data=2;
            curr=curr->next;
            count2--;
        }
        return head;
    }
};

//if no replacement of value allow


class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        Node *curr=head;
        Node *head0=NULL;
        Node *head1=NULL;
        Node *head2=NULL;
        Node *head0tail=NULL;
        Node *head1tail=NULL;
        Node *head2tail=NULL;
         
        
       while(curr){
            if(curr->data==0){
                if(head0==NULL){
                head0=curr;
                head0tail=head0;
                curr=curr->next;
                }
                else{
                head0->next=curr;
                head0=head0->next;
                curr=curr->next;
                }
            }
            else if(curr->data==1){
                 if(head1==NULL){
                head1=curr;
                head1tail=head1;
                curr=curr->next;
                }
                else{
                head1->next=curr;
                 head1=head1->next;
                  curr=curr->next;
                }
            }
           else  if(curr->data==2){
               if(head2==NULL){
                head2=curr;
                head2tail=head2;
                curr=curr->next;
                }
                else{
                head2->next=curr;
                 head2=head2->next;
                 curr=curr->next;
                }
            }
        }  
        // head0->next=head1tail;
        // head1->next=head2tail;
        // head2->next=NULL;
        // return head0tail;
    if (head0) {
    head0->next = head1tail ? head1tail : head2tail; 
     }
    if (head1) {
    head1->next = head2tail?head2tail:NULL; 
    }
    if (head2) {
    head2->next = NULL; 
    }

    if (head0tail) return head0tail; 
    if (head1tail) return head1tail; 
    return head2tail;                
        
    }