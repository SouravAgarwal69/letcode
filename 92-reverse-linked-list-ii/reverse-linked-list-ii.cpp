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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       
        ListNode*Dummy=new ListNode(0);
        Dummy->next=head;
        ListNode*prev=Dummy;
        for(int i=1;i<=left-1;i++)
        {
            prev=prev->next;
        }
        ListNode*curr=prev->next;
        for(int i=1;i<=right-left;i++)
        {
           ListNode*forward=curr->next;
           curr->next=forward->next;
           forward->next=prev->next;
           prev->next=forward;
        }
        return Dummy->next;
    }
};