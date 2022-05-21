class Solution {
    stack<Node*>tmp[6010];
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
        for(int i=0;i<6010;i++){
            while(!tmp[i].empty())tmp[i].pop();
        }
        setNext(0,root);
        return root;
    }
};