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
    int pairSum(ListNode* head) {
        stack<ListNode*>st;
        ListNode*temp=head;
        while(temp)
        {
            st.push(temp);
            temp=temp->next;
        }
        int n=st.size(),cnt=n/2,maxSum=0;
        while(cnt>0)
        {
           maxSum=max(maxSum,st.top()->val+head->val);
           st.pop();
           head=head->next;
           cnt--;
        }
        return maxSum;
    }
};