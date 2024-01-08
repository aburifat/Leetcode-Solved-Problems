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
    int sum(TreeNode* curr, int low, int high){
        if(curr == nullptr) return 0;
        TreeNode* left = curr->left;
        TreeNode* right = curr->right;
        int val = curr->val;
        if(val<low){
            return sum(right,low,high);
        }else if(val>high){
            return sum(left,low,high);
        }else{
            return val + sum(left,low,high) + sum(right,low,high);
        }
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return sum(root, low, high);
    }
};
