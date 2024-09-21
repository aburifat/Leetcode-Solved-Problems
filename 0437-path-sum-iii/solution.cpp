class Solution {
    unordered_map<long long , int> prefSumCount;
    int countPathSum(TreeNode* root, long long currSum, int targetSum) {
        if(root == nullptr) return 0;
        currSum += root->val;
        int count = prefSumCount[currSum - targetSum];
        prefSumCount[currSum]++;
        count += (
            countPathSum(root->left, currSum, targetSum) +
            countPathSum(root->right, currSum, targetSum)
        );
        prefSumCount[currSum]--;

        return count;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        prefSumCount[0] = 1;
        return countPathSum(root, 0, targetSum);
    }
};
