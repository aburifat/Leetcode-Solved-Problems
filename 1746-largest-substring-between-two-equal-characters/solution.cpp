class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int len = s.size();
        int idx[26];
        for(int i=0;i<len;i++){
            idx[s[i]-'a']=i;
        }
        int ans = -1;
        for(int i=0;i<len;i++){
            ans = max(ans,idx[s[i]-'a']-i-1);
        }
        return ans;
    }
};
