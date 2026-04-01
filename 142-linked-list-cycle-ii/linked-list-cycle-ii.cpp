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
    ListNode* findIntersection(ListNode*slow,ListNode*fast)
    {
        while(fast && fast->next)
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
        ListNode *ptr=findIntersection(head,head);
        if(ptr==NULL)
        {
            return NULL;
        }
       ListNode* ptr2=head;
       while(ptr!=ptr2)
       {
          ptr=ptr->next;
          ptr2=ptr2->next;
       }
       return ptr2;
    }
};