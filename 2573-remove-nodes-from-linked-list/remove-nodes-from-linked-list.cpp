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
    ListNode *reverse(ListNode*head)
    {
        ListNode*prev=NULL;
        while(head)
        {
            ListNode*forward=head->next;
            head->next=prev;
            prev=head;
            head=forward;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode*temp=head;
        while(temp)
        {
            while(!st.empty() && st.top()->val<temp->val)
            {
                st.pop();
            }
            st.push(temp);
            temp=temp->next;
        }
        ListNode*prev=NULL;
        while(!st.empty())
        {
            st.top()->next=prev;
            prev=st.top();
             st.pop();
        }
        return prev;
    }
};