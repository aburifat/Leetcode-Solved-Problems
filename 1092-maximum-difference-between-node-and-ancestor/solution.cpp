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
    int goBabe(TreeNode* curr, int mn, int mx){
        int ans = max(abs(curr->val-mn),abs(curr->val-mx));
        mn = min(mn,curr->val);
        mx = max(mx,curr->val);
        if(curr->left!=nullptr)ans = max(ans,goBabe(curr->left,mn,mx));
        if(curr->right!=nullptr)ans = max(ans,goBabe(curr->right,mn,mx));
        return ans;
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        if(root->left!=nullptr)ans = max(ans,goBabe(root->left, root->val, root->val));
        if(root->right!=nullptr)ans = max(ans,goBabe(root->right, root->val, root->val));
        return ans;
    }
};
