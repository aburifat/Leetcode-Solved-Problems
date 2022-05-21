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
    int getMin(int level, TreeNode* node){
        if(node){
            int leftMin=getMin(level+1,node->left);
            int rightMin=getMin(level+1,node->right);
            if(!node->left&&!node->right)level++;
            else if(node->left&&node->right)level=min(leftMin,rightMin);
            else if(!node->left&&node->right)level=rightMin;
            else if(node->left&&!node->right)level=leftMin;
        }
        return level;
    }
public:
    int minDepth(TreeNode* root) {
        int ans=getMin(0,root);
        return ans;
    }
};