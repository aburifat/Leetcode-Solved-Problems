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
    vector<int>levelSum;
    void saveSum(int level,TreeNode* root){
        if(root==nullptr)return;
        if(levelSum.size()<(level+1)){
            while(levelSum.size()<(level+1))levelSum.push_back(0);
        }
        levelSum[level]+=root->val;
        saveSum(level+1,root->left);
        saveSum(level+1,root->right);
    }
    int maxLevelSum(TreeNode* root) {
        saveSum(0,root);
        int mx=levelSum[0];
        int idx=0;
        for(int i=1;i<levelSum.size();i++){
            if(levelSum[i]>mx){
                mx=levelSum[i];
                idx=i;
            }
        }
        return idx+1;
    }
};
