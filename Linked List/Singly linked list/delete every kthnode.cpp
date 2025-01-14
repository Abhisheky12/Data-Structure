class Solution {
  public:
    Node* deleteK(Node* head, int k) {
        // code here
        if(k==1){
            return NULL;
        }
        int count=1;
        Node *prev=NULL;
        Node *curr=head;
        while(curr!=NULL){
            if(k==count){
                prev->next=curr->next;
                delete curr;
                curr=prev->next;
                count=1;
            }
            else{
                prev=curr;
                curr=curr->next;
                count++;
            }
        }
        return head;
        
        
    }
};