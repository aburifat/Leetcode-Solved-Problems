class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        int total = len1;
        int count[26];
        for(int i=0;i<26;i++){
            count[i]=0;
        }
        for(int i=0;i<s1.size();i++){
            count[s1[i]-'a']++;
        }
        if(len2 < total) return false;
        for(int i=0;i<s1.size();i++){
            if(count[s2[i]-'a']>0){
                total--;
            }
            count[s2[i]-'a']--;
        }
        if(total==0)return true;
        for(int i=len1;i<len2;i++){
            count[s2[i-len1]-'a']++;
            if(count[s2[i-len1]-'a'] > 0)total++;
            if(count[s2[i]-'a']>0){
                total--;
            }
            count[s2[i]-'a']--;
            if(total==0) return true;
        }
        return false;
    }
};
