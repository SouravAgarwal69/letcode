/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public static int find(TreeNode root)
    {
        if(root==null)
        {
            return 0;
        }
        return 1+find(root.left)+find(root.right);
    }
    public static boolean check(TreeNode root,int i,int totalNode)
    {
        if(root==null)
        {
            return true;
        }
        if(i>totalNode)
        {
            return false;
        }
        return check(root.left,2*i,totalNode) && check(root.right,2*i+1,totalNode);
    }
    public boolean isCompleteTree(TreeNode root) {
        int totalNode=find(root);
        return check(root,1,totalNode);
    }
}