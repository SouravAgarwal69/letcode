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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;
        ListNode*prev=head,*curr=head->next;
        int pos=1,firstCritical=0,prevCritical=0,minimum=INT_MAX;
        while(curr->next)
        {
            if((curr->val > prev->val && curr->val > curr->next->val) || (curr->val < prev->val && curr->val < curr->next->val))
            {
                if(firstCritical==0)
                {
                    firstCritical=pos;
                }
                else
                {
                    minimum=min(minimum,pos-prevCritical);
                }
                  prevCritical=pos;
            }
            pos++;
            prev=curr;
            curr=curr->next;
        }
        if(minimum==INT_MAX)
        {
            return {-1,-1};
        }
        return{minimum,prevCritical-firstCritical};

    }
};