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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer>result=new ArrayList<>();
        Deque<TreeNode>dq=new ArrayDeque<>();
        if(root!=null)
        {
            dq.offer(root);
        }
        while(!dq.isEmpty())
        {
            int size=dq.size();
            result.add(dq.peekLast().val);
            while(size>0)
            {
                TreeNode temp=dq.peekFirst();
                dq.pollFirst();
                if(temp.left!=null)
                {
                    dq.offer(temp.left);
                }
                if(temp.right!=null)
                {
                    dq.offer(temp.right);
                }
                size--;
            }
        }
        return result;
    }
}