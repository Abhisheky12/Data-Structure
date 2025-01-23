class Solution {
  public:
    Node* reverseBetween(int a, int b, Node* head) {
        //node creation at start
        Node *first=new Node(0);
        first->next=head;
        head=first;
        
        //pointer declaration
        Node *prev,*curr,*tail,*front,*second;
        tail=head;
        a--;
        int c=(b-a)+1;
        while(a){
            tail=tail->next;
            a--;
        }
        prev=tail;
        curr=tail->next;
        second=tail->next;
        while(c){
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
            c--;
        }
        
        tail->next=prev;
        second->next=curr;
        
        first=head;
        head=head->next;
        delete first;
        return head;
        
        
    }
};