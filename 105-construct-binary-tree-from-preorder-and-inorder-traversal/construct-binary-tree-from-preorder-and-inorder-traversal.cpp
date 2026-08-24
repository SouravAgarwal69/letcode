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
    TreeNode*find(vector<int>&preorder,vector<int>&inorder,int s,int e,int &index,unordered_map<int,int>&mp)
    {
        if(s>e)
        {
            return NULL;
        }
        TreeNode*root=new TreeNode(preorder[index]);
         int i=mp[preorder[index]];
         index++;
         root->left=find(preorder,inorder,s,i-1,index,mp);
         root->right=find(preorder,inorder,i+1,e,index,mp);
         return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int index=0;
         return find(preorder,inorder,0,inorder.size()-1,index,mp);
    }
};