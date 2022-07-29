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
    bool ck(TreeNode* l, TreeNode* r){
        if(l==nullptr&&r==nullptr)return true;
        else if(l==nullptr)return false;
        else if(r==nullptr)return false;
        if(l->val!=r->val)return false;
        bool val1=ck(l->left,r->right);
        bool val2=ck(l->right,r->left);
        if(val1&&val2)return true;
        else return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return ck(root->left,root->right);
    }
};
