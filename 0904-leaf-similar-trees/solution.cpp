class Solution {
    queue<int>q;
    void add_leaf(TreeNode* curr){
        if(curr->left == nullptr && curr->right == nullptr){
            q.push(curr->val);
        }
        if(curr->left != nullptr){
            add_leaf(curr->left);
        }
        if(curr->right != nullptr){
            add_leaf(curr->right);
        }
    }

    bool remove_leaf(TreeNode* curr){
        if(curr->left == nullptr && curr->right == nullptr){
            if(!q.empty() && q.front() == curr->val){
                q.pop();
                return true;
            }
            return false;
        }
        bool ck = true;
        if(curr->left != nullptr){
            ck &= remove_leaf(curr->left);
        }
        if(curr->right != nullptr){
            ck &= remove_leaf(curr->right);
        }
        return ck;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        add_leaf(root1);
        if(remove_leaf(root2) && q.empty()){
            return true;
        }
        return false;
    }
};
