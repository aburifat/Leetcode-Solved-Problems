class Solution {
public:
    string convert(string s, int numRows) {
        string ans=s;
        int len=s.size();
        int ct=(numRows-1)*2;
        int idx=0;
        for(int i=0;i<ct;i++){
            int j=(ct-i)%ct;
            if(i>j)break;
            int idx_i=i;
            int idx_j=j;
            while(idx_i<len){
                ans[idx]=s[idx_i];
                idx++;
                if(idx_j!=idx_i&&idx_j<len){
                    ans[idx]=s[idx_j];
                    idx++;
                }
                idx_i+=ct;
                idx_j+=ct;
            }

        }
        return ans;
    }
};
