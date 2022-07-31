class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx=0,l=0,ct=0;
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            ct++;
            if(mp[s[i]]>1){
                mx=max(mx,ct-1);
                while(mp[s[i]]>1){
                    mp[s[l]]--;
                    ct--;
                    l++;
                }
            }
        }
        mx=max(mx,ct);
        return mx;
    }
};