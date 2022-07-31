class Solution {
public:
    string get_origin(string s){
        sort(s.begin(),s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,int>mp;
        vector<string>oridex,emp;
        vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++){
            string origin=get_origin(strs[i]);
            if(!mp[origin]){
                mp[origin]=oridex.size()+1;
                oridex.push_back(origin);
                ans.push_back(emp);
            }
            ans[mp[origin]-1].push_back(strs[i]);
        }
        return ans;
    }
};