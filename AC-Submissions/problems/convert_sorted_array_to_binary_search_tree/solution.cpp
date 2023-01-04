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
    TreeNode* buildBST(vector<int>& nums, int l, int r){
        if(l>r)return nullptr;
        int mid = l+(r-l)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildBST(nums,l,mid-1);
        node->right = buildBST(nums,mid+1,r);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len=nums.size();
        TreeNode* root = buildBST(nums,0,len-1);
        return root;
    }
};