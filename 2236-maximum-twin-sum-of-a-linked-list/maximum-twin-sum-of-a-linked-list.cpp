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
    int pairSum(ListNode* head) {
        vector<int>temp;
        while(head)
        {
            temp.push_back(head->val);
            head=head->next;
        }
        int maxSum=0,s=0,e=temp.size()-1;
        while(s<e)
        {
            maxSum=max(maxSum,temp[s]+temp[e]);
            s++;
            e--;
        }
        return maxSum;
    }
};