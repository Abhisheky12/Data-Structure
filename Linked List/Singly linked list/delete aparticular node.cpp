/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) {
        // cdoe here
        if(x==1){
            Node *temp=head;
            head=head->next;
            delete temp;
            return head;
        }
      
            Node *curr=head;
            Node *prev=NULL;
            x--;
            while(x){
                prev=curr;
                curr=curr->next;
                x--;
            }
            prev->next=curr->next;
            delete curr;
            return head;
    
    }
};