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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,bool>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=true;
        }
        ListNode*temp=head;
        ListNode*Dummy=new ListNode(0);
        Dummy->next=head;
        ListNode*prev=Dummy;
        while(temp)
        {
            if(mp[temp->val])
            {
                prev->next=temp->next;
            }
            else
            {
                prev=temp;
            }
            temp=temp->next;
        }
        return Dummy->next;
    }
};