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
    public boolean isCompleteTree(TreeNode root) {
        boolean nullVisited=false;
        Queue<TreeNode>q=new LinkedList<>();
        if(root!=null)
        {
            q.offer(root);
        }
        while(!q.isEmpty())
        {
            TreeNode node=q.peek();
            q.poll();
            if(node==null)
            {
                nullVisited=true;
            }
            else
            {
               if(nullVisited)
               {
                  return false;
               }
               q.offer(node.left);
               q.offer(node.right);
            }
        }
          return true;
    }
}