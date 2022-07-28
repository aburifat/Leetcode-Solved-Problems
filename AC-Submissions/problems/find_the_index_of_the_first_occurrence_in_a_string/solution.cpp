class Solution {
    vector<int>prefFunc(string s){
        int len=s.size();
        vector<int>pi(len);
        pi[0]=0;
        for (int i=1;i<len;i++) {
            int j=pi[i-1];
            while(j>0&&s[i]!=s[j])
                j=pi[j-1];
            if(s[i]==s[j])
                j++;
            pi[i]=j;
        }
        return pi;
    }
public:
    int strStr(string haystack, string needle) {
        int n_len=needle.size();
        needle=needle+"#"+haystack;
        vector<int>pi=prefFunc(needle);
        int h_len=needle.size();
        int ans=-1;
        for(int i=n_len+1;i<h_len;i++){
            if(pi[i]==n_len){
                ans=i-(2*n_len);
                break;
            }
        }
        return ans;
    }
};