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
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*temp=head;
        unordered_map<int,ListNode*>mp;
        int prefix=0;
        mp[0]=dummy;
        while(temp)
        {
            prefix+=temp->val;
            if(mp.find(prefix)!=mp.end())
            {
                ListNode*ptr=mp[prefix];
                ListNode*curr=ptr;
                int currPrefix=prefix;
                while(curr!=temp)
                {
                   curr=curr->next;
                   currPrefix+=curr->val;
                   if(curr!=temp)
                   {
                     mp.erase(currPrefix);
                   }
                }
                ptr->next=temp->next;
            }
            else
            {
                 mp[prefix]=temp;
            }
             temp=temp->next;
        }
        return dummy->next;
    }
};