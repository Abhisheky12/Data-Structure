/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        int count=0;
        ListNode*temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        count/=2;
        ListNode *curr=head,*prev=NULL;
        while(count){
            prev=curr;
            curr=curr->next;
            count--;
        }
        prev->next=NULL;
        ListNode *Front=NULL;
        prev=NULL;
        while(curr){
            Front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Front;
        }
        ListNode *head1=head,*head2=prev;
        while(head1){
             if(head1->val!=head2->val){
                return false;
             }
             head1=head1->next;
             head2=head2->next;

        }
        return true;
    }
};