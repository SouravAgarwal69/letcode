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
        vector<ListNode*>result;
        int n=0;
        ListNode*temp=head;
        while(temp)
        {
            n++;
            temp=temp->next;
        }
        int equal=n/k,rem=n%k;
        temp=head;
        while(k--)
        {
            ListNode*Dummy=new ListNode();
            Dummy->next=temp;
            ListNode*tail=Dummy;
            int cnt=equal;
            while(cnt>0)
            {
                tail->next=temp;
                tail=tail->next;
                temp=temp->next;
                cnt--;
            }
            if(rem>0)
            {
                tail->next=temp;
                temp=temp->next;
                tail=tail->next;
                rem--;
            }
            tail->next=NULL;
            result.push_back(Dummy->next);
        }
        return result;
    }
};