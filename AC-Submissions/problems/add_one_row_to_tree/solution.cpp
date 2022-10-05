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
    TreeNode* addNode(int val, TreeNode* root, bool left){
        TreeNode* tmp=new TreeNode();
        tmp->val=val;
        if(left)tmp->left=root;
        else tmp->right=root;
        return tmp;
    }
    TreeNode* findDeep(int level, TreeNode* root, int val, int depth){
        if(level>=depth||root==nullptr)return root;
        else if(level==depth-1){
            root->left=addNode(val,root->left,true);
            root->right=addNode(val,root->right,false);
        }else{
            root->left=findDeep(level+1,root->left,val,depth);
            root->right=findDeep(level+1,root->right,val,depth);
        }
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            root=addNode(val,root,true);
        }else{
            root=findDeep(1,root,val,depth);
        }
        return root;
    }
};