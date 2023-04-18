class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1=word1.size();
        int len2=word2.size();
        int len=min(len1,len2);
        string s="";
        for(int i=0;i<len;i++){
            s+=word1[i];
            s+=word2[i];
        }
        for(int i=len;i<len1;i++){
            s+=word1[i];
        }
        for(int i=len;i<len2;i++){
            s+=word2[i];
        }
        return s;
    }
};
