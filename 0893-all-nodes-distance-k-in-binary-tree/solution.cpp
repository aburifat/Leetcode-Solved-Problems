/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int>dis;

    int init(TreeNode* root, TreeNode* target, int k){
        if(root->val==target->val)return dis[root->val]=k;
        int tmp = -1;
        if(root->left!=NULL)tmp = max(tmp,init(root->left,target,k)-1);
        if(root->right!=NULL) tmp = max(tmp,init(root->right,target,k)-1);
        if(tmp!=-1) dis[root->val] = tmp;
        return tmp;
    }

    void goBabe(TreeNode* root){
        int tmp = dis[root->val];
        if(root->left!=NULL){
            dis[root->left->val]=max(dis[root->left->val],tmp-1);
            goBabe(root->left);
        }
        if(root->right!=NULL){
            dis[root->right->val]=max(dis[root->right->val],tmp-1);
            goBabe(root->right);
        }
    }

public:

    Solution(){
        dis.assign(510,-1);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int tmp = init(root,target,k);
        goBabe(root);
        vector<int>ans;
        for(int i=0;i<510;i++)if(dis[i]==0)ans.push_back(i);
        return ans;
    }
};
