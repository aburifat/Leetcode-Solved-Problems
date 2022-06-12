class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size();
        map<int,int>mp;
        int ct=0;
        int ans=0;
        for(int i=0,j=0;i<len&&j<len;j++){
            if(!mp[s[j]]){
                ct++;
                mp[s[j]]++;
            }else{
                ans=max(ans,ct);
                while(i<j){
                    if(s[i]==s[j]){
                        i++;
                        break;
                    }else{
                        ct--;
                        mp[s[i]]--;
                        i++;
                    }
                }
            }
            if(j==len-1)ans=max(ans,ct);
        }
        return ans;
    }
};
