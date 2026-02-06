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
        int total=0;
        ListNode*temp=head;
        while(temp)
        {
           total++;
           temp=temp->next;
        }
        int move=total-n;
        ListNode*prev=Dummy;
        temp=head;
        while(move>0)
        {
            prev=temp;
            temp=temp->next;
            move--;
        }
        prev->next=temp->next;
        temp->next=NULL;
        delete temp;
        return Dummy->next;
    }
};