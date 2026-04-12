/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode*find(ListNode*slow,ListNode*fast)
    {
        while(fast && fast->next )
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                return slow;
            }
        }
       return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow=head,*fast=head;
        ListNode*intersection=find(slow,fast);
        if(!intersection)
        {
            return intersection;
        }
        while(head!=intersection)
        {
            head=head->next;
            intersection=intersection->next;
        }
        return head;
    }
};