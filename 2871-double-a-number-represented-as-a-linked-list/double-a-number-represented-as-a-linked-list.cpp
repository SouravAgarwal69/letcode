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
        if(!head || !head->next)
        {
            return head;
        }
        ListNode*revHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return revHead;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode*revHead=reverse(head);
        int value=0,carry=0;
       ListNode* prev=NULL;
        while(revHead)
        {
            value+=revHead->val*2;
            carry=value/10;
            ListNode*temp=new ListNode(value%10);
            temp->next=prev;
            prev=temp;
            value=carry;
            revHead=revHead->next;
        }
        if(carry!=0)
        {
            ListNode*ptr=new ListNode(carry);
            ptr->next=prev;
            prev=ptr;
        }
        return prev;
    }
};