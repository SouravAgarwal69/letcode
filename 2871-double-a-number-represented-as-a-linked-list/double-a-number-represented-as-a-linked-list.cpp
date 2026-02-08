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
    ListNode*reverse(ListNode*head)
    {
        ListNode*prev=NULL,*curr=head;
        while(curr)
        {
            ListNode*forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode*revHead=reverse(head),*prev=NULL;
        ListNode*temp=revHead;
        int value=0,carry=0;
        while(temp)
        {
             value=value+(temp->val*2);
             carry=value/10;
             temp->val=value%10;
             value=carry;
             prev=temp;
             temp=temp->next;
        }
        if(carry!=0)
        {
            ListNode*ptr=new ListNode(carry);
            prev->next=ptr;
        }
        return reverse(revHead);
    }
};