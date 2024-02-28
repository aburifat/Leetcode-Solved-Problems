public class Solution
{
    private int value = -1;
    private int mxDepth = -1;
    private void findValue(TreeNode curr, int depth)
    {
        if(curr.left != null) findValue(curr.left,depth+1);
        if(curr.right != null) findValue(curr.right,depth+1);
        if(depth > mxDepth && curr.left == null && curr.right == null)
        {
            value = curr.val;
            mxDepth = depth;
        }
    }
    public int FindBottomLeftValue(TreeNode root) {
        findValue(root,0);
        return value;
    }
}
