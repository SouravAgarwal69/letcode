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
    ListNode* doubleIt(ListNode* head) {
        ListNode*prev=NULL,*curr=head;
        int result=0,carry=0;
        while(curr)
        {
           result=curr->val*2;
           carry=result/10;
           if(carry!=0)
           {
              if(!prev)
              {
                head=new ListNode(carry);
                head->next=curr;
              }
              else
              {
                prev->val=prev->val+carry;
              }
           }
           curr->val=result%10;
           prev=curr;
           curr=curr->next;
        }
         return head;
    }
};