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
    int index=0;
    TreeNode*find(vector<int>&inorder,vector<int>&postorder,int s,int e,unordered_map<int,int>&mp,int &index)
    {
        if(s>e)
        {
            return NULL;
        }
        TreeNode*root=new TreeNode(postorder[index]);
        int i=mp[postorder[index]];
        index--;
        root->right=find(inorder,postorder,i+1,e,mp,index);
        root->left=find(inorder,postorder,s,i-1,mp,index);
        return root;
    } 
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int n=inorder.size(),index=inorder.size()-1;
         return find(inorder,postorder,0,n-1,mp,index);
    }
};