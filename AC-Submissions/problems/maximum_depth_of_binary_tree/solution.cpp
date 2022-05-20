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
    int getLevel(int level, TreeNode* node){
        if(node){
            int leftLevel=getLevel(level+1,node->left);
            int rightLevel=getLevel(level+1,node->right);
            level=max(level,max(leftLevel,rightLevel));
        }
        return level;
    }
    int maxDepth(TreeNode* root) {
        int level=getLevel(0,root);
        return level;
    }
};