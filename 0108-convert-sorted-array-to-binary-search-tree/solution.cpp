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
    void build_bst(TreeNode* head, vector<int>& nums, int l, int r){
        if(l>r)return;
        int mid=l+(r-l)/2;
        head->val=nums[mid];
        TreeNode* left=new TreeNode();
        TreeNode* right=new TreeNode();
        if(l!=r){
            if(mid!=l){
                head->left=left;
                build_bst(left,nums,l,mid-1);
            }
            if(mid!=r){
                head->right=right;
                build_bst(right,nums,mid+1,r);
            }
        }
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len=nums.size();
        TreeNode* head=new TreeNode();
        build_bst(head,nums,0,len-1);
        return head;
    }
};
