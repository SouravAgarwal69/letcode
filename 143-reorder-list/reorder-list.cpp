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
    ListNode*front;
    void recursion(ListNode*head)
    {
        if(!head)
        {
            return;
        }
        recursion(head->next);
         if(!front)
        {
            return;
        }
        if(front==head || front->next==head)
        {
            head->next=NULL;
            front=NULL;
            return;
        }
        ListNode*temp=front->next;
        front->next=head;
        head->next=temp;
        front=temp;
    }
    void reorderList(ListNode* head) {
        front=head;
        recursion(head);
    }
};