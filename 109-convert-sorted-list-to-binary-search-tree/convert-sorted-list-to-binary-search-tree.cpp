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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* construct(vector<int>&arr,int s,int e)
    {
        if(s>e)
        {
            return NULL;
        }
        int mid=s+(e-s)/2;
        TreeNode* temp=new TreeNode(arr[mid]);
        temp->left=construct(arr,s,mid-1);
        temp->right=construct(arr,mid+1,e);
        return temp;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>arr;
        while(head)
        {
            arr.push_back(head->val);
            head=head->next;
        }
      return  construct(arr,0,arr.size()-1);
    }
};