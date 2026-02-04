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
   ListNode* reverseLL(ListNode*head)
   {
      if(!head || !head->next)
      {
         return head;
      }
      ListNode* revHead=reverseLL(head->next);
      head->next->next=head;
      head->next=NULL;
      return revHead;
   }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseLL(l1);
        l2=reverseLL(l2);
        ListNode*ans=new ListNode(0);
        int sum=0,carry=0;
         while(l1 || l2)
         {
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            ans->val=(sum%10);
            carry=sum/10;
            ListNode* NewNode=new ListNode(carry);
            NewNode->next=ans;
            ans=NewNode;
            sum=carry;
         }
         return carry==0?ans->next:ans;
    }
};