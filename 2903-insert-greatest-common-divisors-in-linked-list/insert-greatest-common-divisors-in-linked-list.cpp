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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode*nextNode=insertGreatestCommonDivisors(head->next);
        int gcd=__gcd(head->val,nextNode->val);
        ListNode*temp=new ListNode(gcd);
        head->next=temp;
        temp->next=nextNode;
        return head;
    }
};