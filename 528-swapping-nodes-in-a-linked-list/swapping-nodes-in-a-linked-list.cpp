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
        int n=1;
        ListNode*temp=head;
        ListNode*ptr=head;
        while(temp)
        {
            if(n==k)
            {
                ptr=temp;
            }
            temp=temp->next;
            n++;
        }
        int cnt=n-k;
        temp=head;
        while(cnt>1)
        {
            temp=temp->next;
            cnt--;
        }
      swap(temp->val,ptr->val);
      return head;
    }
};