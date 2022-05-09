class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenHay=haystack.size();
        int lenNed=needle.size();
        int ans=-1;
        for(int i=0;i<lenHay;i++){
            if(haystack[i]==needle[0]){
                int ct=0;
                for(int j=0;j<lenNed;j++){
                    if(haystack[i+j]==needle[j])ct++;
                    else break;
                }
                if(ct==lenNed){
                    ans=i;
                    break;
                }
            }
        }
        return ans;
    }
};
