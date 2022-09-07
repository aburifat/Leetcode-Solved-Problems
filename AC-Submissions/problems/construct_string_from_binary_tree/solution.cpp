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

string getstr(TreeNode* root){
    if(root==nullptr)return "";
    string s="(";
    s+=to_string(root->val);
    string s_left=getstr(root->left);
    string s_right=getstr(root->right);
    if(s_left!=""&&s_right!=""){
        s=s+s_left+s_right;
    }else if(s_right!=""){
        s=s+"()"+s_right;
    }else if(s_left!=""){
        s=s+s_left;
    }
    s+=")";
    return s;
}

class Solution {
public:
    string tree2str(TreeNode* root) {
        string s="";
        s+=to_string(root->val);
        string s_left=getstr(root->left);
        string s_right=getstr(root->right);
        if(s_left!=""&&s_right!=""){
            s=s+s_left+s_right;
        }else if(s_right!=""){
            s=s+"()"+s_right;
        }else if(s_left!=""){
            s=s+s_left;
        }
        return s;
    }
};