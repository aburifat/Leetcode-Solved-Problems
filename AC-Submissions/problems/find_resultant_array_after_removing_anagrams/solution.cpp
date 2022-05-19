class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string s="";
        vector<string>ans;
        for(int i=0;i<(int)words.size();i++){
            string tmp=words[i];
            int len=tmp.size();
            sort(tmp.begin(),tmp.end());
            if(s!=tmp){
                ans.push_back(words[i]);
                s=tmp;
            }
        }
        return ans;
    }
};