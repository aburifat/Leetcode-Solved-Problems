bool findSecondValue(TreeNode* brother, TreeNode* curr, int k){
    if(curr==nullptr)return false;
    if(curr->val==k&&curr!=brother)return true;
    else if((curr->val)<k)return findSecondValue(brother,curr->right,k);
    else return findSecondValue(brother,curr->left,k);
    return false;
}
bool solve(TreeNode* root, TreeNode* curr, int k){
    if(curr==nullptr)return false;
    int dif=k-(curr->val);
    bool ck=findSecondValue(curr,root, dif);
    if(ck)return true;
    return solve(root,curr->left,k)|solve(root,curr->right,k);
}
 
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        return solve(root,root,k);
    }
};
