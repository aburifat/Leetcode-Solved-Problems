class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int len=edges.size();
        vector<int>node(len+5,0);
        for(int i=0;i<len;i++){
            node[edges[i][0]]++;
            if(node[edges[i][0]]>1)return edges[i][0];
            node[edges[i][1]]++;
            if(node[edges[i][1]]>1)return edges[i][1];
        }
        return 1;
    }
};
