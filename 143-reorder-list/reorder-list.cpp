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
    void reorderList(ListNode* head) {
        stack<ListNode*>st;
        ListNode*temp=head;
        while(temp)
        {
            st.push(temp);
            temp=temp->next;
        }
       int k=st.size()/2;
       temp=head;
       while(k--)
       {
          ListNode*ptr=temp->next;
          temp->next=st.top();
          st.top()->next=ptr;
          st.pop();
          temp=ptr;
       }
       temp->next=NULL;
    }
};