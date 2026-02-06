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
        ListNode* revHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return revHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head,*fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*reverseHead=reverse(slow->next);
        while(head && reverseHead)
        {
            if(head->val!=reverseHead->val)
            {
                return false;
            }
            head=head->next;
            reverseHead=reverseHead->next;
        }
        return true;
    }
};