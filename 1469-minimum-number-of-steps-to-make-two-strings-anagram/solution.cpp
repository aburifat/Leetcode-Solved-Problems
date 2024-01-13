class Solution {
public:
    int minSteps(string s, string t) {
        int ct[26];
        memset(ct,0,sizeof(ct));
        int len = s.size();
        for(int i=0;i<len;i++){
            ct[s[i]-'a']++;
            ct[t[i]-'a']--;
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            ans+=abs(ct[i]);
        }
        ans = (ans/2) + (ans%2!=0);
        return ans;
    }
};
