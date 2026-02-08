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
    int recursion(ListNode*head)
    {
        if(!head)
        {
            return 0;
        }
        int carry=recursion(head->next);
        int value=carry+head->val*2;
        head->val=value%10;
        return value/10;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry=recursion(head);
       if(carry!=0)
       {
          ListNode*temp=new ListNode(carry);
          temp->next=head;
          head=temp;
       }
       return head;
    }
};