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
    bool ck(TreeNode* node, int l, int r, bool l_min, bool r_max){
        if(node==nullptr)return true;
        if(node->val<l||node->val>r)return false;
        if(l_min==true||r_max==true)return false;
        bool val1=true,val2=true;
        bool mn=false,mx=false;
        int ll=node->val,rr=node->val;
        if(node->val==INT_MAX){
            mx=true;
        }else rr++;
        if(node->val==INT_MIN)mn=true;
        else ll--;
        val1=ck(node->left,l,ll,l_min,mn);
        val2=ck(node->right,rr,r,l_min,mx);
        if(val1&&val2)return true;
        else return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return ck(root,INT_MIN,INT_MAX,false,false);
    }
};