public class Solution {
    private Dictionary<int,int> levelValue = new();
    private bool CheckTree(TreeNode curr, int level){
        if(!levelValue.ContainsKey(level)){
            levelValue[level] = (level % 2 == 0) ? 0 : 1000010;
        }

        if(level%2 == 0 && (curr.val % 2 == 0 || levelValue[level] >= curr.val)) return false;
        else if(level%2 != 0 && (curr.val % 2 != 0 || levelValue[level] <= curr.val)) return false;
        levelValue[level] = curr.val;
        
        bool ck = true;
        if(curr.left != null) ck &= CheckTree(curr.left, level + 1);
        if(curr.right != null) ck &= CheckTree(curr.right, level + 1);
        return ck;
    }
    public bool IsEvenOddTree(TreeNode root) {
        return CheckTree(root, 0);
    }
}
