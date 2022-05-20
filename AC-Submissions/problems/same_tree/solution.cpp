class Solution {
public:
    bool ckTheTrees(TreeNode* p, TreeNode* q){
        if(!p||!q)return p==q;
        if(p->val!=q->val)return false;
        bool ckLeft=ckTheTrees(p->left,q->left);
        bool ckRight=ckTheTrees(p->right,q->right);
        if(!ckLeft||!ckRight)return false;
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans=ckTheTrees(p,q);
        return ans;
    }
};