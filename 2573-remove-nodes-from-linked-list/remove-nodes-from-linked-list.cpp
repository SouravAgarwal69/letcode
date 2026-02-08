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
    ListNode* removeNodes(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode*Forward=removeNodes(head->next);
        if(Forward->val<=head->val)
        {
            head->next=Forward;
            Forward=head;
        }
        return Forward;
    }
};