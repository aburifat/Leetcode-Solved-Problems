 typedef long long ll;
class Solution {
public:
    string frequencySort(string s) {
        ll len=s.size();
        vector<pair<ll,char>>v;
        map<char,ll>mp;
        for(ll i=0;i<len;i++){
            if(!mp[s[i]]){
                mp[s[i]]=v.size()+1;
                v.push_back({1,s[i]});
            }else{
                ll idx=mp[s[i]]-1;
                v[idx].first++;
            }
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        string ans="";
        for(ll i=0;i<v.size();i++){
            for(ll j=0;j<v[i].first;j++)ans+=v[i].second;
        }
        return ans;
    }
};