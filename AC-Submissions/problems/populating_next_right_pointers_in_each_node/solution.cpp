/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    stack<Node*>tmp[2010];
public:
    void setNext(int level,Node* node){
        if(node){
            if(tmp[level].size()!=0)tmp[level].top()->next=node;
            tmp[level].push(node);
            setNext(level+1,node->left);
            setNext(level+1,node->right);
        }
    }
    Node* connect(Node* root) {
        for(int i=0;i<2010;i++){
            while(!tmp[i].empty())tmp[i].pop();
        }
        setNext(0,root);
        return root;
    }
};