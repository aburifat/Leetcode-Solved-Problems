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
    void goBabe(TreeNode* node, vector<int>& ans){
        if(node==nullptr)return;
        TreeNode* leftChild=node->left;
        TreeNode* rightChild=node->right;
        goBabe(leftChild,ans);
        ans.push_back(node->val);
        goBabe(rightChild,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        goBabe(root,ans);
        return ans;
    }
};