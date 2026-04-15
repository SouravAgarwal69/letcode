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
        ListNode*Dummy=new ListNode();
        Dummy->next=head;
        int total=0;
        unordered_map<int,ListNode*>mp;
        mp[0]=Dummy;
        while(head)
        {
            total+=head->val;
            if(mp.find(total)!=mp.end())
            {
                int curr_val=total;
                ListNode*curr=mp[total];
                 ListNode*ptr=curr->next;
                while(ptr!=head)
                {
                   curr_val+=ptr->val;
                   mp.erase(curr_val);
                   ptr=ptr->next;
                }
                curr->next=head->next;
            }
            else
            {
                mp[total]=head;
            }
            head=head->next;
        }
        return Dummy->next;
    }
};