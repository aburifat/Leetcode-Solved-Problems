class Solution {
public:
    int nn,n,mx_mask;
    vector<vector<int>>mem;
    int GCD(int a, int b){
        return __gcd(a,b);
    }
    int dp(int mask, int idx,vector<int>& nums){
        if(mask==mx_mask)return 0;
        if(mem[mask][idx]!=-1)return mem[mask][idx];
        int ans=0;
        for(int i=0;i<nn;i++){
            if(!(mask&(1<<i))){
                for(int j=i+1;j<nn;j++){
                    if(!(mask&(1<<j))){
                        int new_mask=mask|(1<<i);
                        new_mask|=(1<<j);
                        int val=(idx+1)*GCD(nums[i],nums[j]);
                        val+=dp(new_mask,idx+1,nums);
                        ans=max(ans,val);
                    }
                }
            }
        }
        return mem[mask][idx]=ans;
    }
    int maxScore(vector<int>& nums) {
        nn=nums.size();
        n=nn/2;
        mx_mask=(1<<nn)-1;
        mem.assign(mx_mask,vector<int>(n,-1));
        int ans=dp(0,0,nums);
        return ans;
    }
};
