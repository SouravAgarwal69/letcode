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
    ListNode*reverseLL(ListNode*head)
    {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode*revHead=reverseLL(head->next);
        head->next->next=head;
        head->next=NULL;
        return revHead;
    }
    int pairSum(ListNode* head) {
        ListNode*slow=head,*fast=slow;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*ptr=reverseLL(slow->next);
        int maxSum=0;
        while(ptr)
        {
           maxSum=max(maxSum,ptr->val+head->val);
           head=head->next;
           ptr=ptr->next;
        }
        return maxSum;
    }
};