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
        ListNode*Dummy=new ListNode(0);
        Dummy->next=head;
        unordered_map<int,ListNode*>mp;
        mp[0]=Dummy;
        int prefix=0;
        while(head)
        {
            prefix+=head->val;
            if(mp.find(prefix)!=mp.end())
            {
                ListNode*ptr=mp[prefix];
                ListNode*curr=ptr;
                int curr_prefix=prefix;
                while(curr!=head)
                {
                    curr=curr->next;
                    curr_prefix+=curr->val;
                    if(curr!=head)
                    {
                        mp.erase(curr_prefix);
                    }
                }
                ptr->next=head->next;
            }
            else
            {
                mp[prefix]=head;
            }
            head=head->next;
        }
        return Dummy->next;
    }
};