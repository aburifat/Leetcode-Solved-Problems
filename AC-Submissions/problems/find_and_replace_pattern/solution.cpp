class Solution {
    string formatWord(string s){
        int len=s.size();
        map<char,int>mp;
        vector<char>v;
        v.push_back('#');
        for(int i=0;i<len;i++){
            if(!mp[s[i]]){
                v.push_back(s[i]);
                mp[s[i]]=v.size()-1;
            }
            s[i]=(mp[s[i]]+'0');
        }
        return s;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int len=words.size();
        vector<string>formatedWords;
        for(int i=0;i<len;i++){
            formatedWords.push_back(formatWord(words[i]));
        }
        pattern=formatWord(pattern);
        vector<string>ans;
        for(int i=0;i<len;i++){
            if(pattern.size()!=formatedWords[i].size())continue;
            bool ck=true;
            for(int j=0;j<pattern.size();j++){
                if(pattern[j]!=formatedWords[i][j]){
                    ck=false;
                    break;
                }
            }
            if(ck)ans.push_back(words[i]);
        }
        return ans;
    }
};