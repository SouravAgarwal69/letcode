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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*>mp;
        ListNode*Dummy=new ListNode(0);
        Dummy->next=head;
        ListNode*temp=Dummy;
        int prefixSum=0;
        while(temp)
        {
            prefixSum+=temp->val;
            if(mp.find(prefixSum)!=mp.end())
            {
                 ListNode*start=mp[prefixSum];
                 ListNode*curr=start->next;
                 int currSum=prefixSum;
                 while(curr!=temp)
                 {
                    currSum+=curr->val;
                    mp.erase(currSum);
                    curr=curr->next;
                 }
                 start->next=temp->next;
            }
            else
            {
                mp[prefixSum]=temp;
            }
            temp=temp->next;
        }
        return Dummy->next;
    }
};