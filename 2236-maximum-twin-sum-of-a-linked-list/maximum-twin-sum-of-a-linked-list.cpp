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
        stack<int>st;
        ListNode*temp=head;
        while(temp)
        {
           st.push(temp->val);
           temp=temp->next;
        }
        int cnt=st.size()/2,maxSum=0;
        while(cnt>0)
        {
           maxSum=max(maxSum,head->val+st.top());
           head=head->next;
           st.pop();
           cnt--;
        }
        return maxSum;
    }
};