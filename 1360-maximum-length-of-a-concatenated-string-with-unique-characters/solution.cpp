class Solution {
    bool unique(vector<bool> ck, string s){
        for(int i=0;i<(int)s.size();i++){
            int idx = s[i]-'a';
            if(ck[idx])return false;
            ck[idx]=true;
        }
        return true;
    }
    vector<bool> merge(vector<bool> ck,string s){
        for(int i=0;i<(int)s.size();i++){
            int idx = s[i]-'a';
            ck[idx]=true;
        }
        return ck;
    }
    int setCount(vector<bool>ck){
        int ct = 0;
        for(int i=0;i<26;i++)if(ck[i]==true)ct++;
        return ct;
    }
    void solve(int idx, vector<bool>& ck, vector<string>& v, int& ans){
        int len = v.size();
        if(idx>=len)return;
        solve(idx+1,ck,v,ans);
        if(unique(ck,v[idx])){
            ans = max(ans,setCount(ck)+(int)v[idx].size());
            vector<bool>newCk = merge(ck,v[idx]);
            solve(idx+1,newCk,v,ans);
        }
    }
public:
    int maxLength(vector<string>& arr) {
        vector<bool>ck(26,false);
        vector<string> v;
        for(int i=0;i<(int)arr.size();i++){
            if(unique(ck,arr[i]))v.push_back(arr[i]);
        }
        int ans = 0;
        solve(0,ck,v,ans);
        return ans;
    }
};
