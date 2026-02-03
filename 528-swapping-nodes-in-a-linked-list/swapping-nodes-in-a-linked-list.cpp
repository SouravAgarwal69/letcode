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
       ListNode*temp=head,*ptr1=head,*ptr2=head;
       int cnt=1;
       while(temp)
       {
          temp=temp->next;
          cnt++;
       }
       int value=cnt-k;
       while(k>1)
       {
          ptr1=ptr1->next;
          k--;
       }
       while(value>1)
       {
          ptr2=ptr2->next;
          value--;
       }
       int v=ptr1->val;
       ptr1->val=ptr2->val;
       ptr2->val=v;
       return head;
    }
};