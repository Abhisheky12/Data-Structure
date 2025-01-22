class Solution {
    public:
        // Function to find intersection
    Node* intersectPoint(Node* head1, Node* head2) {
        Node *curr1=head1;
        Node *curr2=head2;
        
        //calculating length of both linked list
        int count1=0;
        int count2=0;
        while(curr1){
            curr1=curr1->next;
            count1++;
            
        }
        while(curr2){
            curr2=curr2->next;
            count2++;
            
        }
        curr1=head1;
        curr2=head2;
        while(count1>count2){
            curr1=curr1->next;
            count1--;
        }
          while(count2>count1){
            curr2=curr2->next;
            count2--;
        }
        while(curr1!=curr2){
             curr1=curr1->next;
             curr2=curr2->next;
        }
        // if(curr1==NULL || curr2==NULL){
        //     return ;
        // }
        return curr1;
    }
};