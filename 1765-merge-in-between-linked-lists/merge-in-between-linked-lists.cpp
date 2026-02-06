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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*Dummy=new ListNode();
        Dummy->next=list1;
        ListNode*prev=Dummy;
        while(a>0)
        {
            prev=prev->next;
            a--;
        }
        ListNode*forward=list1;
        while(b>=0)
        {
            forward=forward->next;
            b--;
        }
        ListNode*tail=list2;
        while(tail->next)
        {
            tail=tail->next;
        }
        prev->next=list2;
        tail->next=forward;
        return Dummy->next;
    }
};