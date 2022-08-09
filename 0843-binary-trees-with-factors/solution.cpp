class Solution {
    map<int,int>mp;
    vector<int>dp;
    int mod=1e9+7;
    int ctDp(vector<int>& arr, int idx, int n){
        if(idx>=n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        long long val=1;
        for(int i=idx-1;i>=0;i--){
            int dif=arr[idx]/arr[i];
            if((dif*arr[i])==arr[idx]&&mp[dif]){
                int difIdx=mp[dif]-1;
                long long left=ctDp(arr,difIdx,n);
                long long right=ctDp(arr,i,n);
                long long tmpVal;
                tmpVal=(left*right)%mod;
                val=(val+tmpVal)%mod;
            }
        }
        return dp[idx]=(int)val;
    }
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        mp.clear();
        sort(arr.begin(),arr.end());
        int len=arr.size();
        for(int i=0;i<len;i++)mp[arr[i]]=i+1;
        dp.assign(len+5,-1);
        int ans=0;
        for(int i=len-1;i>=0;i--){
            if(dp[i]==-1){
                int tmp=ctDp(arr,i,len);
            }
            ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};
