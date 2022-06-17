/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void goBabe(Node* node, vector<int>& ans){
        if(node==nullptr)return;
        vector<Node*>childNodes=node->children;
        int len=childNodes.size();
        for(int i=0;i<len;i++){
            goBabe(childNodes[i],ans);
        }
        ans.push_back(node->val);
    }
    vector<int> postorder(Node* root) {
        vector<int>ans;
        goBabe(root,ans);
        return ans;
    }
};