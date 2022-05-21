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
    bool ckSum(int sum, TreeNode* node, int targetSum){
        if(node){
            sum+=node->val;
            if(!node->left&&!node->right){
                if(sum==targetSum)return true;
                else return false;
            }else if(!node->left){
                return ckSum(sum,node->right,targetSum);
            }else if(!node->right){
                return ckSum(sum,node->left,targetSum);
            }else{
                bool ckLeft=ckSum(sum,node->left,targetSum);
                bool ckRight=ckSum(sum,node->right,targetSum);
                if(ckLeft||ckRight)return true;
                else return false;
            }
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans=ckSum(0,root,targetSum);
        return ans;
    }
};
