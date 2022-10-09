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
    bool findVal(TreeNode* brother, TreeNode* curr, int k){
        if(curr==nullptr)return false;
        if(curr->val==k&&curr!=brother)return true;
        else if(curr->val<k)return findVal(brother,curr->right,k);
        else return findVal(brother,curr->left,k);
        return false;
    }
    bool goBabe(TreeNode* root, TreeNode* curr, int k){
        if(curr==nullptr)return false;
        int dif=k-(curr->val);
        bool ck=findVal(curr,root, dif);
        if(ck)return true;
        return goBabe(root,curr->left,k)|goBabe(root,curr->right,k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        return goBabe(root,root,k);
    }
};