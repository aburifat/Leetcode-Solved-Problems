class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>ans;
        int m=0;
        if(n>0)m=matrix[0].size();
        vector<vector<bool>>visited(n+5,vector<bool>(m+5,false));
        int i=0,j=0,k=n,l=m;
        while(i>=0&&i<n&&j>=0&&j<m){
            if(visited[i][j]==true)break;
           for(int o=j;o<l;o++){
               if(!visited[i][o]){
                   visited[i][o]=true;
                    ans.push_back(matrix[i][o]);
               }
           }
            for(int o=i;o<k;o++){
                if(!visited[o][l-1]){
                    visited[o][l-1]=true;
                    ans.push_back(matrix[o][l-1]);
                }
            }
            for(int o=l-1;o>=0;o--){
                if(!visited[k-1][o]){
                    visited[k-1][o]=true;
                    ans.push_back(matrix[k-1][o]);
                }
            }
            for(int o=k-1;o>=0;o--){
                if(!visited[o][j]){
                    visited[o][j]=true;
                    ans.push_back(matrix[o][i]);
                }
            }
            i++,j++,k--,l--;
        }
        return ans;
    }
};