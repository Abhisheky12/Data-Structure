class Solution {
  public:
  
    Node* reverse(Node *curr,Node *prev){
            if(curr==NULL){
                return prev;
            }
            Node *front=curr->next;
            curr->next=prev;
            return reverse(front,curr);
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
       
        num1=reverse(num1,NULL);
        num2=reverse(num2,NULL);
        Node *curr1=num1;
        Node *curr2=num2;
        Node *head=new Node(0);
        Node *tail=head;
        int sum,carry=0;
        

        
        while(curr1 &&curr2){
            sum=curr1->data+curr2->data+carry;
            tail->next=new Node(sum%10);
            tail=tail->next;
            curr1=curr1->next;
            curr2=curr2->next;
            carry=sum/10;
        }
        while(curr1){
            sum=curr1->data+carry;
            tail->next=new Node(sum%10);
            tail=tail->next;
            curr1=curr1->next;
            carry=sum/10;
        }
        while(curr2){
            sum=curr2->data+carry;
            tail->next=new Node(sum%10);
            tail=tail->next;
            curr2=curr2->next;
            carry=sum/10;
        }
        while(carry){
            tail->next=new Node(carry%10);
            tail=tail->next;
            carry=carry/10;
        }
        Node *result=reverse(head->next,NULL);
        delete head;
        return result;
    }
};