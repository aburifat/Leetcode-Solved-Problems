class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int len=words.size();
        map<pair<char,char>,int>mp;
        int ct=0;
        int samect=0;
        for(int i=0;i<len;i++){
            if(words[i][0]==words[i][1]){
                if(mp[{words[i][0],words[i][1]}]){
                    samect--;
                    ct+=4;
                    mp[{words[i][0],words[i][1]}]--;
                }else{
                    mp[{words[i][0],words[i][1]}]++;
                    samect++;
                }
            }else{
                if(mp[{words[i][1],words[i][0]}]){
                    ct+=4;
                    mp[{words[i][1],words[i][0]}]--;
                }else{
                    mp[{words[i][0],words[i][1]}]++;
                }
            }
        }
        if(samect)ct+=2;
        return ct;
    }
};
