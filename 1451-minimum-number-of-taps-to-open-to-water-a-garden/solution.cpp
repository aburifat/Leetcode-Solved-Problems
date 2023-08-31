class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>ct(n+1,1e9);
        ct[0]=0;
        for(int i=0;i<=n;i++){
            if(ranges[i]==0)continue;
            int l=max(0,i-ranges[i]);
            int r=min(n,i+ranges[i]);
            for(int j=l;j<r;j++)ct[r]=min(ct[r],ct[j]+1);
        }
        if(ct[n]==1e9)return -1;
        else return ct[n];
    }
};
