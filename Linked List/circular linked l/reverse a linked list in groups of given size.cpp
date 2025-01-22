class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node *first=new Node(0);
        first->next=head;
        head=first;
        Node *second,*curr,*prev,*front;
        while(first->next)
        {
        int x=k;
        second=first->next;
        curr=first->next;
        prev=first;
        while(x &&curr){
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
            x--;
        }
        first->next=prev;
        second->next=curr;
        first=second;
        }
        first=head;
        head=head->next;
        delete first;
        return head;
    }
};