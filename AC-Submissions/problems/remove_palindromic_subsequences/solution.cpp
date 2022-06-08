class Solution {
public:
    int removePalindromeSub(string s) {
        for(int i=0,j=(int)s.size()-1;i<=j;i++,j--){
            if(s[i]!=s[j])return 2;
        }
        return 1;
    }
};