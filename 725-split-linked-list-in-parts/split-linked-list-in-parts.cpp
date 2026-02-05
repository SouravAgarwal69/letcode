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
        int n=0;
        ListNode*temp=head;
        while(temp)
        {
            n++;
            temp=temp->next;
        }
        int each=n/k;
        int rem=n%k;
        while(k>0)
        {
            ListNode*Dummy=new ListNode();
            ListNode*ptr=Dummy;
            int size=each;
            while(size>0 && head)
            {
                ptr->next=head;
                 ptr=head;
                head=head->next;
                size--;
            }
            if(rem>0)
            {
                ptr->next=head;
                  ptr=head;
                head=head->next;
                rem--;
            }
            k--;
            if(ptr)
            {
            ptr->next=NULL;
            }
            ans.push_back(Dummy->next);
        }
        return ans;
    }
};