int mod=1e9+7;
class Solution {
public:
    int concatenatedBinary(int n) {
        int ans=0;
        int binpow=1;
        while(n){
            int val=n;
            while(val){
                if(val&1){
                    ans=(ans+binpow)%mod;
                }
                val=(val>>1);
                binpow=(binpow<<1)%mod;
            }
            n--;
        }
        return ans;
    }
};
