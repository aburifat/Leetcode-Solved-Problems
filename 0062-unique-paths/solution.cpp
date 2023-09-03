class Solution {
public:
    int dp(int i, int j, int m, int n, vector<vector<int>>& mem){
        if(i>=m||j>=n)return 0;
        if(i==m-1&&j==n-1)return 1;
        if(mem[i][j]!=-1)return mem[i][j];
        return mem[i][j]=dp(i+1,j,m,n,mem)+dp(i,j+1,m,n,mem);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>mem(m,vector<int>(n,-1));
        int ans = dp(0,0,m,n,mem);
        return ans;
    }
};
