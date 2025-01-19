



  // 2 2 2 3 3 4 4linked list 
class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {

        // code here
        Node *curr=head->next;
        Node *prev=head;
        while(curr!=NULL){
            if(prev->data==curr->data){
                prev->next=curr->next;
                delete curr;
                curr=prev->next;
            }
            else{
                prev=prev->next;
                curr=curr->next;
            }
        }
        return head;
    }
};