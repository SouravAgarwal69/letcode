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
    void reorderList(ListNode* head) {
        ListNode*slow=head,*fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
       ListNode* revHead= reverse(slow->next);
       slow->next=NULL;
        while(revHead)
        {
             ListNode*temp=head->next;
             ListNode*revtemp=revHead->next;
             head->next=revHead;
             revHead->next=temp;
             head=temp;
             revHead=revtemp;
        }
    }
};