/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    int getDepth(TreeNode node, int depth){
        int now_depth = depth + 1;
        if(node.left != null){
            now_depth = Math.Max(now_depth,getDepth(node.left,depth+1));
        }
        if(node.right != null){
            now_depth = Math.Max(now_depth,getDepth(node.right,depth+1));
        }
        return now_depth;
    }
    public int MaxDepth(TreeNode root) {
        int ans = 0;
        if(root!=null)ans=getDepth(root,0);
        return ans;
    }
}
