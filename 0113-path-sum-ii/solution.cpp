class Solution {
    vector<vector<int>> ans;
    vector<int> container;

    void checkPath(TreeNode* root, int currSum) {
        if(root == nullptr) return;
        currSum -= root->val;
        container.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            if(currSum == 0) {
                ans.push_back(container);
            }
        }
        else {
            checkPath(root->left, currSum);
            checkPath(root->right, currSum);
        }
        container.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        checkPath(root, targetSum);
        return ans;
    }
};
