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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode*OddHead=head,*EvenHead=head->next,*EvenTail=head->next,*OddTail=head;
        while(EvenTail && EvenTail->next)
        {
            OddTail->next=OddTail->next->next;
            EvenTail->next=EvenTail->next->next;
            OddTail=OddTail->next;
            EvenTail=EvenTail->next;
        }
        OddTail->next=EvenHead;
        return OddHead;
    }
};