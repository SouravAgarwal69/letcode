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
    int findGcd(int a,int b)
    {
        while(b!=0)
        {
            int rem=a%b;
            a=b;
            b=rem;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode*temp=head;
        while(temp->next)
        {
            int gcd=findGcd(temp->val,temp->next->val);
            ListNode*ptr=new ListNode(gcd);
            ListNode*forward=temp->next;
            temp->next=ptr;
            ptr->next=forward;
            temp=forward;
        }
        return head;
    }
};