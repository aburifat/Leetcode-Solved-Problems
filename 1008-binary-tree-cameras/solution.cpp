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
    int cnt=0;
    map<TreeNode*,int>cover;
    TreeNode* mainRoot;
public:
    void visitNodes(TreeNode* node){
        if(node==nullptr)return;
        TreeNode* leftChild=node->left;
        TreeNode* rightChild=node->right;
        visitNodes(leftChild);
        visitNodes(rightChild);
        if(leftChild!=nullptr&&rightChild!=nullptr){
            if((!cover[leftChild])||(!cover[rightChild])){
                cover[leftChild]=2;
                cover[rightChild]=2;
                cover[node]=1;
                cnt++;
            }else if(cover[leftChild]==1||cover[rightChild]==1)cover[node]=2;
        }else if(leftChild!=nullptr){
             if(!cover[leftChild]){
                 cover[leftChild]=2;
                 cover[node]=1;
                 cnt++;
             }else if(cover[leftChild]==1)cover[node]=2;
        }else if(rightChild!=nullptr){
             if(!cover[rightChild]){
                 cover[rightChild]=2;
                 cover[node]=1;
                 cnt++;
             }else if(cover[rightChild]==1)cover[node]=2;
        }
        if(node==mainRoot&&!cover[mainRoot])cnt++;
    }
    int minCameraCover(TreeNode* root) {
        cnt=0;
        mainRoot=root;
        visitNodes(root);
        if(cnt==0)cnt++;
        return cnt;
    }
};
