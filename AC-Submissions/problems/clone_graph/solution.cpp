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


bool visited[110];

void init(){
    for(int i=0;i<110;i++){
        visited[i]=false;
    }
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        init();
        if(node==nullptr)return nullptr;
        vector<Node*>nodeList(110);
        nodeList[node->val]=node;
        visited[node->val]=true;
        queue<Node*>q;
        vector<int>nodeVal;
        nodeVal.push_back(1);
        q.push(node);
        while(!q.empty()){
            node=q.front();
            q.pop();
            for(int i=0;i<node->neighbors.size();i++){
                if(!visited[node->neighbors[i]->val]){
                    visited[node->neighbors[i]->val]=true;
                    q.push(node->neighbors[i]);
                    nodeList[node->neighbors[i]->val]=node->neighbors[i];
                    
                    nodeVal.push_back(node->neighbors[i]->val);
                }
            }
        }
        vector<Node*>newNodes;
        for(int i=0;i<=110;i++){
            Node* tmp=new Node();
            newNodes.push_back(tmp);
        }
        sort(nodeVal.begin(),nodeVal.end());
        Node* root=newNodes[1];
        for(int i=0;i<nodeVal.size();i++){
            newNodes[nodeVal[i]]->val=nodeVal[i];
        }
        for(int i=0;i<nodeVal.size();i++){
            Node* tmp=nodeList[nodeVal[i]];
            for(int j=0;j<tmp->neighbors.size();j++){
                int val=tmp->neighbors[j]->val;
                newNodes[nodeVal[i]]->neighbors.push_back(newNodes[val]);
            }
        }
        return root;
    }
};