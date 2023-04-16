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
    map<int,vector<TreeNode*>>dp;
    vector<TreeNode*>getDP(int n){
        vector<TreeNode*>ans;
        if(n==0||n%2==0)return ans;
        if(dp.find(n)!=dp.end())return dp[n];
        TreeNode* root = new TreeNode();
        if(n==1){
            ans.push_back(root);
            return ans;
        }
        for(int i=1;i<n-1;i+=2){
            int j=n-i-1;
            vector<TreeNode*>left=getDP(i);
            vector<TreeNode*>right=getDP(j);
            for(auto leftnode:left){
                for(auto rightnode:right){
                    root = new TreeNode(0,leftnode,rightnode);
                    ans.push_back(root);
                }
            }
        }
        return dp[n]=ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        dp.clear();
        return getDP(n);

    }
};
