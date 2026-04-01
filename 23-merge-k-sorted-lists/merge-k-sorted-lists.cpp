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
    ListNode*merge(ListNode*L1,ListNode*L2)
    {
        if(!L1)
        {
            return L2;
        }
        if(!L2)
        {
            return L1;
        }
        if(L1->val<L2->val)
        {
            L1->next=merge(L1->next,L2);
            return L1;
        }
        else
        {
            L2->next=merge(L1,L2->next);
            return L2;
        }
    }
    ListNode*split(vector<ListNode*>&lists,int s,int e)
    {
        if(s==e)
        {
            return lists[s];
        }
        int mid=s+(e-s)/2;
        ListNode* L1=split(lists,s,mid);
        ListNode* L2=split(lists,mid+1,e);
        return merge(L1,L2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
        {
            return NULL;
        }
        return  split(lists,0,lists.size()-1);
    }
};