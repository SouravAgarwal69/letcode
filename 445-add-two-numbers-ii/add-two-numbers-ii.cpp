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
        if(!head || !head->next)
        {
            return head;
        }
        ListNode*rev=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return rev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode*head=NULL;
        l1=reverse(l1);
        l2=reverse(l2);
        while(l1 && l2)
        {
           int sum=l1->val+l2->val+carry;
            ListNode*temp=new ListNode(sum%10);
            carry=sum/10;
            temp->next=head;
            head=temp;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            int sum=l1->val+carry;
            ListNode*temp=new ListNode(sum%10);
            temp->next=head;
            head=temp;
            carry=sum/10;
            l1=l1->next;
        }
        while(l2)
        {
            int sum=l2->val+carry;
            ListNode*temp=new ListNode(sum%10);
            temp->next=head;
            head=temp;
            carry=sum/10;
            l2=l2->next;
        }
        if(carry!=0)
        {
            ListNode*temp=new ListNode(carry);
            temp->next=head;
            head=temp;
        }
        return head;
    }
};