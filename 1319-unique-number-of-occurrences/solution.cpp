class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        int mx=0;
        for(int i=0;i<(int)arr.size();i++){
            mp[arr[i]]++;
            if(mp[arr[i]]>mx)mx=mp[arr[i]];
        }
        bool ck[mx+1];
        memset(ck,false,sizeof(ck));
        for(auto it=mp.begin();it!=mp.end();it++){
            if(ck[it->second])return false;
            ck[it->second]=true;
        }
        return true;
    }
};
