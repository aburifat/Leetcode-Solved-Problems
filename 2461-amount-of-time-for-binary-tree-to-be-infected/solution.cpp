class Solution {
    int infTime;
    bool init(TreeNode* curr, int start){
        bool ck = false, lft_ck = false, rgt_ck = false;

        if(curr->val == start){
            ck = true;
            curr->val = 0;
        }

        if(curr->left != nullptr){
            lft_ck = init(curr->left,start);
            if(!ck && lft_ck)curr->val = curr->left->val + 1;
            ck |= lft_ck;
        }

        if(curr->right != nullptr){
            rgt_ck = init(curr->right,start);
            if(!ck && rgt_ck)curr->val = curr->right->val + 1;
            ck |= rgt_ck;
        }
        if(!ck)curr->val = -1;
        return ck;
    }

    void maxInfactionTime(TreeNode* curr){
        infTime = max(infTime,curr->val);
        if(curr->left != nullptr){
            if(curr->left->val == -1){
                curr->left->val = curr->val + 1;
            }
            maxInfactionTime(curr->left);
            infTime = max(infTime, curr->left->val);
        }
        if(curr->right != nullptr){
            if(curr->right->val == -1){
                curr->right->val = curr->val + 1;
            }
            maxInfactionTime(curr->right);
            infTime = max(infTime, curr->right->val);
        }
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        init(root,start);
        maxInfactionTime(root);
        return infTime;
    }
};
