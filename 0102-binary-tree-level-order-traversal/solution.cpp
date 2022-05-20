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
    vector<vector<int>> levelOrder(TreeNode* root) {
        tmp.assign(MX,vector<int>());
        ans.clear();
        insertByLevel(0,root);
        for(int i=0;i<2010;i++){
            if((int)tmp[i].size()==0)break;
            ans.push_back(tmp[i]);
        }
        return ans;
    }
};
