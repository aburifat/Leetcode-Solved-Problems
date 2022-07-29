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
    TreeNode* buildTree(vector<int>& nums,int l, int r){
        if(l>r)return nullptr;
        int mid=l+(r-l)/2;
        TreeNode* node=new TreeNode();
        node->val=nums[mid];
        node->left=buildTree(nums,l,mid-1);
        node->right=buildTree(nums,mid+1,r);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len=nums.size();
        TreeNode* head=buildTree(nums,0,len-1);
        return head;
    }
};
