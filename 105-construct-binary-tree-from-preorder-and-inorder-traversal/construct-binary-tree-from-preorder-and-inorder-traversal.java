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
    int index=0;
    public  TreeNode find(int[]preorder,int[]inorder,int s,int e,HashMap<Integer,Integer>map)
    {
        if(s>e)
        {
            return null;
        }
        int rootVal=preorder[index];
        index++;
        TreeNode root=new TreeNode(rootVal);
        int i=map.get(rootVal);
        root.left=find(preorder,inorder,s,i-1,map);
        root.right=find(preorder,inorder,i+1,e,map);
        return root;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        HashMap<Integer,Integer>map=new HashMap<>();
        int n=inorder.length;
        for(int i=0;i<n;i++)
        {
            map.put(inorder[i],i);
        }
        return find(preorder,inorder,0,n-1,map);
    }
}