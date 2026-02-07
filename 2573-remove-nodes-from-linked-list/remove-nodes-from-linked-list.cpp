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
    ListNode*curr=NULL;
    int max=INT_MIN;
    void reverse(ListNode*head)
    {
        if(!head)
        {
            return ;
        }
        reverse(head->next);
        if(max<=head->val)
        {
        head->next=curr;
        curr=head;
        max=head->val;
        }
    }
    ListNode* removeNodes(ListNode* head) {
        reverse(head);
        return curr;
    }
};