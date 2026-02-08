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
    int value=0,carry=0;
    ListNode*prev=NULL;
   void recursion(ListNode*head)
   {
        if(!head)
        {
            return;
        }
        recursion(head->next);
         value+=head->val*2;
        carry=value/10;
        ListNode*temp=new ListNode(value%10);
        temp->next=prev;
        prev=temp;
        value=carry;
   }
    ListNode* doubleIt(ListNode* head) {
     recursion(head);
    if(carry!=0)
    {
        ListNode*temp=new ListNode(carry);
        temp->next=prev;
        prev=temp;
    }
    return prev;
    }
};