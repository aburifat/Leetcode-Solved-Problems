class Solution {
public:
    int dp[1010][1010];
    int getAns(int l, int r, string& s){
        if(l==r)return 1; // Same index
        if(l>r)return 0; // Base value
        if(dp[l][r]!=-1)return dp[l][r]; // Using memorization
        int ans;
        if(s[l]==s[r]) ans = 2 + getAns(l+1,r-1,s); // Matched two Chars
        else ans = max(getAns(l+1,r,s),getAns(l,r-1,s)); // Getting maximum ans
        return dp[l][r]=ans;
    }
    int longestPalindromeSubseq(string s) {
        for(int i=0;i<1010;i++){
            for(int j=0;j<1010;j++)dp[i][j]=-1;
        }
        int ans = getAns(0,s.size()-1,s);
        return ans;
    }
};