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
   ListNode*reverse(ListNode*curr)
   {
      ListNode*prev=NULL;
      while(curr)
      {
         ListNode*forward=curr->next;
          curr->next=prev;
          prev=curr;
          curr=forward;
      }
      return prev;
   }
    int pairSum(ListNode* head) {
        int maxSum=0;
        ListNode*slow=head,*fast=head;
        while(fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*ptr=reverse(slow->next);
        while(ptr)
        {
            maxSum=max(maxSum,ptr->val+head->val);
            head=head->next;
            ptr=ptr->next;
        }
        return maxSum;
    }
};