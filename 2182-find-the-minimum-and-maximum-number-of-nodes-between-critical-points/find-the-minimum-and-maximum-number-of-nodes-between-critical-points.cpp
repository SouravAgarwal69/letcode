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
        int firstCritical=-1,prevCritical=-1,critical=0;
        int minimum=INT_MAX;
        ListNode*prev=head,*curr=head->next;
        int pos=1;
        while(curr->next)
        {
            if((curr->val > prev->val && curr->val > curr->next->val) ||(curr->val < prev->val && curr->val < curr->next->val))
            {
                    if(firstCritical==-1)
                    {
                        firstCritical=pos;
                        prevCritical=pos;
                    }
                    else
                    {
                        minimum=min(minimum,pos-prevCritical);
                        prevCritical=pos;
                    }  
                    critical++;
            }
            prev=curr;
            curr=curr->next;
            pos++;
        }
        if(critical<2)
        {
            return {-1,-1};
        }
        return {minimum,prevCritical-firstCritical};
    }
};