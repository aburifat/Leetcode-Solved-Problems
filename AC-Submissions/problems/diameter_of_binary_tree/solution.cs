public class Solution {
    private int mxLength = 0;
    private int getLength(TreeNode curr){
        if(curr == null) return 0;
        int leftLength = getLength(curr.left);
        int rightLength = getLength(curr.right);
        mxLength = Math.Max(mxLength, leftLength + rightLength);
        return 1 + Math.Max(leftLength, rightLength);
    }
    public int DiameterOfBinaryTree(TreeNode root) {
        getLength(root);
        return mxLength;
    }
}