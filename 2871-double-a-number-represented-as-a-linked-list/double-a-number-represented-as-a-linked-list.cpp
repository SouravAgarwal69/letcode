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
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode*>st;
        while(head)
        {
            st.push(head);
            head=head->next;
        }
        int value=0,carry=0;
        ListNode*prev=NULL;
        while(!st.empty())
        {
             value+=st.top()->val*2;
             st.pop();
             carry=value/10;
             ListNode*temp=new ListNode(value%10);
             temp->next=prev;
             prev=temp;
             value=carry;
        }
        if(carry!=0)
        {
            ListNode*temp=new ListNode(carry);
            temp->next=prev;
            prev=temp;
        }
        return prev;
    }
};