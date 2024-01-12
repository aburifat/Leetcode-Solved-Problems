class Solution {
    string vowel = "aeiou";
public:
    bool halvesAreAlike(string s) {
        int len = s.size();
        int mid = len/2;
        int ct = 0;
        for(int i=0;i<len;i++){
            if(s[i]<='Z')s[i]=(s[i]-'A'+'a');
            for(auto c : vowel){
                if(c==s[i]){
                    if(i<mid)ct++;
                    else ct--;
                    break;
                }
            }
        }
        if(!ct)return true;
        return false;
    }
};
