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
    int calculate(TreeNode*root)
    {
        if(!root)
        {
            return 0;
        }
        return 1+calculate(root->left)+calculate(root->right);
    }
    bool check(TreeNode*root,int TotalNode,int i)
    {
        if(!root)
        {
            return true;
        }
        if(i>TotalNode)
        {
            return false;
        }
        return check(root->left,TotalNode,2*i) && check(root->right,TotalNode,2*i+1);
    }
    bool isCompleteTree(TreeNode* root) {
        int TotalNode=calculate(root);
         return check(root,TotalNode,1);
    }
};