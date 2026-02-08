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
        ListNode*prev=NULL;
        ListNode*curr=head;
        while(curr)
        {
            ListNode*forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode*revHead=reverse(head);
        ListNode*prev=revHead;
        ListNode*curr=prev->next;
        while(curr)
        {
            if(prev->val<=curr->val)
            {
                prev->next=curr;
                prev=curr;
            }
            curr=curr->next;
        }
        prev->next=NULL;
        return reverse(revHead);
    }
};