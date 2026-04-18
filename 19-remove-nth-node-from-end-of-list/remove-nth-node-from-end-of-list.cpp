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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next)
        {
            return NULL;
        }
        int total=0;
        ListNode*temp=head;
        while(temp)
        {
            total++;
            temp=temp->next;
        }
        if(total==n)
        {
            return head->next;
        }
        temp=head;
        for(int i=1;i<total-n;i++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};