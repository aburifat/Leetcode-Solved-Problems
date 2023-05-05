class Solution {
public:
    int maxVowels(string s, int k) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int cnt=0,ans=0;
        string vowel="aeiou";
        bool ck[26];
        for(int i=0,j=0;i<26;i++){
            if(i==(vowel[j]-'a')){
                ck[i]=true;
                j++;
            }else{
                ck[i]=false;
            }
        }
        for(int i=0;i<(int)s.size();i++){
            if(i>=k&&ck[(s[i-k]-'a')])cnt--;
            if(ck[(s[i]-'a')])cnt++;
            ans=(cnt>ans)?cnt:ans;
        }
        return ans;
    }
};
