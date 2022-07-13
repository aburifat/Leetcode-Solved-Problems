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

void dfs(vector<vector<int>> &v, TreeNode* node, int level){
    vector<int>emp;
    while(v.size()<=level)v.push_back(emp);
    v[level].push_back(node->val);
    TreeNode* left=node->left;
    TreeNode* right=node->right;
    if(left!=nullptr)dfs(v,left,level+1);
    if(right!=nullptr)dfs(v,right,level+1);
}

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root!=nullptr)dfs(ans,root,0);
        return ans;
    }
};