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
    bool ckTrees(TreeNode* p, TreeNode* q){
        if(!p||!q)return p==q;
        if(p->val!=q->val)return false;
        bool ckLeft=ckTrees(p->left,q->right);
        bool ckRight=ckTrees(p->right,q->left);
        if(!ckLeft||!ckRight)return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* p=root->left;
        TreeNode* q=root->right;
        bool ans=ckTrees(p,q);
        return ans;
    }
};
