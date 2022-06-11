class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        long long q=spells.size();
        vector<int>v=potions;
        long long n=potions.size();
        sort(v.begin(),v.end());
        vector<int>ans;
        for(long long i=0;i<q;i++){
            long long val=success/spells[i];
            if(success%spells[i])val++;
            long long ct=lower_bound(v.begin(),v.end(),val)-v.begin();
            if(ct>=n)ans.push_back(0);
            else{
                if(ct<0)ct=0;
                if(v[ct]<val)ct++;
                val=n-ct;
                ans.push_back(val);
            }
        }
        return ans;
    }
};
