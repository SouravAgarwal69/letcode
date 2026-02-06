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
        Dummy->next=head;
        ListNode*prev=Dummy;
        int total=0;
        ListNode*temp=head;
        while(temp)
        {
            total++;
            temp=temp->next;
        }
        int result=total-n;
         while(result>0)
         {
            prev=prev->next;
            result--;
         }
         ListNode* toDelete=prev->next;
         prev->next=toDelete->next;
         delete toDelete;
         return Dummy->next;
    }
};