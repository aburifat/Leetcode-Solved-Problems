class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        istringstream words(text);
        string s;
        map<char,bool>mp;
        for(int i=0;i<brokenLetters.size();i++){
            mp[brokenLetters[i]]=true;
        }
        int ct=0;
        while(words >> s){
            bool ck=true;
            for(int i=0;i<s.size();i++){
                if(mp[s[i]]){
                    ck=false;
                    break;
                }
            }
            if(ck)ct++;
        }
        return ct;
    }
};
