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
    ListNode* partition(ListNode* head, int x) {
        ListNode*Dummy1=new ListNode();
        ListNode*tail1=Dummy1;
        ListNode*Dummy2=new ListNode();
        ListNode*tail2=Dummy2;
        while(head)
        {
            if(head->val<x)
            {
                tail1->next=head;
                tail1=tail1->next;
            }
            else
            {
                tail2->next=head;
                tail2=tail2->next;
            }
            head=head->next;
        }
        tail1->next=Dummy2->next;
        tail2->next=NULL;
        return Dummy1->next;
    }
};