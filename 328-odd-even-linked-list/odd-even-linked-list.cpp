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
        ListNode*oddHead=head,*oddTail=head,*evenHead=head->next,*evenTail=head->next;
        while(evenTail && evenTail->next)
        {
            oddTail->next=evenTail->next;
            evenTail->next=evenTail->next->next;
            oddTail=oddTail->next;
            evenTail=evenTail->next;
        }
        oddTail->next=evenHead;
        return oddHead;
    }
};