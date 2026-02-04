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
      ListNode*prev=NULL,*curr=head;
      while(curr)
      {
        ListNode*forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
      }
      return prev;
   }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseLL(l1);
        l2=reverseLL(l2);
        ListNode*ans=new ListNode();
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
            ans->val=sum%10;
            carry=sum/10;
            sum=carry;
            ListNode* NewNode=new ListNode(carry);
            NewNode->next=ans;
            ans=NewNode;
        }
        return ans->val==0?ans->next:ans;
    }
};