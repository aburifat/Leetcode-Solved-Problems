/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    bool visited[110];
    Node* new_add[110];
    Node* clone(Node* node){
        Node* new_node = new Node(node->val);
        visited[node->val]=true;
        new_add[node->val]=new_node;
        for(int i=0;i<(int)node->neighbors.size();i++){
            if(visited[node->neighbors[i]->val])new_node->neighbors.push_back(new_add[node->neighbors[i]->val]);
            else new_node->neighbors.push_back(clone(node->neighbors[i]));
        }
        return new_node;
    }
public:
    Node* cloneGraph(Node* node) {
        for(int i=0;i<110;i++)visited[i]=false;
        Node* root = nullptr;
        if(node!=nullptr)root=clone(node);
        return root;
    }
};
