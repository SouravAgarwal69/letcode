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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*ptr=head,*curr=head->next;
        int sum=0;
        while(curr)
        {
            sum+=curr->val;
            if(curr->val==0)
            {
                ptr->val=sum;
                ptr->next=curr->next;
                ptr=curr->next;
                sum=0;
            }
            curr=curr->next;
        }
        return head;
    }
};