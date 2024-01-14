class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int ct1[26],ct2[26];
        for(int i=0;i<26;i++){
            ct1[i]=ct2[i]=0;
        }
        for(int i=0;i<(int)word1.size();i++){
            ct1[word1[i]-'a']++;
        }
        for(int i=0;i<(int)word2.size();i++){
            ct2[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(ct1[i]==0 || ct2[i]==0){
                if(ct1[i]!=0 || ct2[i]!=0){
                    return false;
                }
            }
        }
        sort(ct1,ct1+26);
        sort(ct2,ct2+26);
        for(int i=0;i<26;i++){
            if(ct1[i]!=ct2[i])return false;
        }
        return true;
    }
};
