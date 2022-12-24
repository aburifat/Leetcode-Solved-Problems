class Solution {
public:
    int mod=1e9+7;
    map<int,long long>fact;
    
    long long fact_mod(int n){
        if(n==0||n==1)return 1;
        if(fact[n])return fact[n];
        return fact[n]=(n*fact_mod(n-1))%mod;
    }

    long long binpow(long long base, long long power){
        base%=mod;
        power%=(mod-1);
        long long result=1;
        while(power>0){
            if(power&1)result=(result*base)%mod;
            base=(base*base)%mod;
            power>>=1;
        }
        return result;
    }
    
    long long modInv(long long a){
        return binpow(a,mod-2);
    }
    
    int ct_per_word(string s){
        int len=s.size();
        int ct[26];
        for(int i=0;i<26;i++)ct[i]=0;
        for(int i=0;i<len;i++)ct[s[i]-'a']++;
        long long ans=fact_mod(len);
        for(int i=0;i<26;i++){
            if(ct[i]>1){
                int val=modInv(fact_mod(ct[i]));
                ans=(ans*val)%mod;
            }
        }
        return ans;
    }
    int countAnagrams(string s) {
        istringstream is(s);
        string tmp;
        long long ans=1;
        while(is>>tmp){
            long long per=ct_per_word(tmp);
            ans=(ans*per)%mod;
        }
        return ans;
    }
};