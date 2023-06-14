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
    int gtDif(TreeNode* root, int& mx, int& mn){
        int now_mx = root->val;
        int now_mn = root->val;
        int val = 1e9;
        if(root->left!=nullptr){
            val = min(val,gtDif(root->left,mx,mn));
            val=min(val,abs(root->val-mx));
            now_mn=mn;
        }
        if(root->right!=nullptr){
            val = min(val,gtDif(root->right,mx,mn));
            val=min(val,abs(root->val-mn));
            now_mx=mx;
        }
        mx=now_mx;
        mn=now_mn;
        return val;
    } 
    int getMinimumDifference(TreeNode* root) {
        int mx;
        int mn;
        int ans = gtDif(root,mx,mn);
        return ans;
    }
};
