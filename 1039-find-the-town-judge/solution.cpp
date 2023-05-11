class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>iTrust(n+5,0),uTrust(n+5,0);
        for(int i=0;i<(int)trust.size();i++){
            int u=trust[i][0];
            int v=trust[i][1];
            iTrust[u]++;
            uTrust[v]++;
        }
        for(int i=1;i<=n;i++){
            if(iTrust[i]==0&&uTrust[i]==n-1)return i;
        }
        return -1;
    }
};
