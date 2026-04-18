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
        ListNode*Dummy=new ListNode();
        ListNode*prev=Dummy;
        Dummy->next=head;
        int total=0;
        ListNode*temp=head;
        while(temp)
        {
            total++;
            temp=temp->next;
        }
        for(int i=1;i<=total-n;i++)
        {
            prev=prev->next;
        }
        prev->next=prev->next->next;
        return Dummy->next;
    }
};