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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        int total=0;
        ListNode*temp=head;
        while(temp)
        {
            total++;
            temp=temp->next;
        }
        int EachList=total/k;
        int rem=total%k;
        while(k>0)
        {
            ListNode*Dummy=new ListNode();
            ListNode*ptr=Dummy;
            int size=EachList+(rem>0?1:0);
            if(rem>0)
            {
                rem--;
            }
            while(size>0)
            {
                ptr->next=head;
                ptr=head;
                head=head->next;
                size--;
            }
            ptr->next=NULL;
            ans.push_back(Dummy->next);
            k--;
        }
        return ans;
    }
};