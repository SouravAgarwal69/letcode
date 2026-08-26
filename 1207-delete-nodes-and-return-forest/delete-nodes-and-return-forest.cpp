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
    TreeNode* find(TreeNode* root,unordered_set<int>st,vector<TreeNode*>&result)
    {
        if(!root)
        {
            return NULL;
        }
        root->left=find(root->left,st,result);
        root->right=find(root->right,st,result);
        if(st.find(root->val)!=st.end())
        {
            if(root->left)
            {
                result.push_back(root->left);
            }
            if(root->right)
            {
                result.push_back(root->right);
            }
            return NULL;
        }
        else
        {
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>result;
        unordered_set<int>st;
        for(int i=0;i<to_delete.size();i++)
        {
            st.insert(to_delete[i]);
        }
        find(root,st,result);
        if(st.find(root->val)==st.end())
        {
            result.push_back(root);
        }
        return result;
    }
};