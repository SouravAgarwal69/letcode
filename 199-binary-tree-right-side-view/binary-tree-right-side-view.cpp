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
   void find(TreeNode*root,vector<int>&result,int level)
   {
       if(!root)
       {
           return;
       }
        if(result.size()<level)
        {
            result.push_back(root->val);
        }
       find(root->right,result,level+1);
       find(root->left,result,level+1);
   }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        find(root,result,1);
        return result;
    }
};