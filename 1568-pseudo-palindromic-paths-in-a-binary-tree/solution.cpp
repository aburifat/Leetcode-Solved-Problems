class Solution {
    bool odd[10];
    int ctPath(TreeNode* curr){
        int ans = 0;
        odd[curr->val]=!odd[curr->val];
        if(curr->left!=nullptr)ans+=ctPath(curr->left);
        if(curr->right!=nullptr)ans+=ctPath(curr->right);
        if(curr->left==nullptr && curr->right==nullptr){
            int ct = 0;
            for(int i=1;i<10;i++){
                if(odd[i])ct++;
            }
            if(ct<=1)ans=1;
        }
        odd[curr->val]=!odd[curr->val];
        return ans;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        memset(odd,false,sizeof(odd));
        return ctPath(root);
    }
};
