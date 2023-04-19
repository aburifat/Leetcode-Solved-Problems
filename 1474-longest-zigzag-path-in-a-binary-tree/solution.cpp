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
    int ans;
    void getLen(bool dir, TreeNode* root, int dis){
        if(root==nullptr){
            ans=max(ans,dis);
            return;
        }
        TreeNode* child1=(dir)?root->right:root->left;
        TreeNode* child2=(!dir)?root->right:root->left;
        getLen(!dir,child1,dis+1);
        getLen(dir,child2,0);
    }
public:
    int longestZigZag(TreeNode* root) {
        ans=0;
        getLen(true,root->left,0);
        getLen(false,root->right,0);
        return ans;
    }
};
