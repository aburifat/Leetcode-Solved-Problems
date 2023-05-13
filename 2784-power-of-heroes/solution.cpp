typedef long long ll;
class Solution {
public:
    ll mod = 1e9+7;
    int sumOfPower(vector<int>& numsx) {
        vector<ll>nums;
        ll len=numsx.size();
        for(ll i=0;i<len;i++)nums.push_back(numsx[i]);
        sort(nums.begin(),nums.end());
        ll ans=0;
        if(len>=1){
            ans=(((nums[0]*nums[0])%mod)*nums[0])%mod;
        }
        if(len>=2){
            ans=(ans+(((nums[1]*nums[1])%mod)*((nums[0]+nums[1])%mod))%mod)%mod;
        }
        ll sum2=nums[0];
        for(ll i=2;i<len;i++){
            ll sum1=(nums[i]+nums[i-1])%mod;
            sum2=(sum2*2)%mod;
            ans=(ans+((nums[i]*nums[i])%mod)*((sum1+sum2)%mod))%mod;
            sum2=(sum2+nums[i-1])%mod;
        }
        return (int)ans;
    }
};
