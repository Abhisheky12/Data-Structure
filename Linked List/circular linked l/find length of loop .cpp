class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node *slow=head;
        Node *fast=head;
        int count=1;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=slow->next;
                while(slow!=fast){
                    slow=slow->next;
                     count++;
                }
                return count;
            }
        }
        return 0;
        
        
    }
};