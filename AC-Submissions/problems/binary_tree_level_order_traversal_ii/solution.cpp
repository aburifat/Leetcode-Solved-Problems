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
    int MX=2010;
    vector<vector<int>>tmp,ans;
public:
    void insertByLevel(int level, TreeNode* node){
        if(node){
            tmp[level].push_back(node->val);
            insertByLevel(level+1,node->left);
            insertByLevel(level+1,node->right);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        tmp.assign(MX,vector<int>());
        ans.clear();
        insertByLevel(0,root);
        for(int i=0;i<2010;i++){
            if((int)tmp[i].size()==0)break;
            ans.push_back(tmp[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};