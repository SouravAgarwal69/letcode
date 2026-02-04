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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*ptr1=NULL,*temp=head,*ptr2=head;
        int cnt=1;
        while(temp)
        {
            if(ptr2)
            {
                ptr2=ptr2->next;
            }
            if(cnt==k)
            {
                ptr2=head;
                ptr1=temp;
            }
            temp=temp->next;
            cnt++;
        }
        swap(ptr1->val,ptr2->val);
        return head;
    }
};