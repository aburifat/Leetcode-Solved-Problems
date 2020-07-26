const int MAX_LEN=1000;
    int mem[1000][1000];
    int n, m;
int lcs(int i, int j, string &s1, string &s2){
    if(i==0||j==0)return 0;
    if(mem[i][j]!=-1){
        return mem[i][j];
    }
    int ans=0;
    if(s1[i-1]==s2[j-1])ans=1+lcs(i-1,j-1,s1,s2);
    else ans=max(lcs(i-1,j,s1,s2),lcs(i,j-1,s1,s2));
    return mem[i][j]=ans;
}
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        n=text1.size();
        m=text2.size();
        memset(mem, -1, sizeof mem);
        int ans=lcs(n,m,text1,text2);
        return ans;
    }
};