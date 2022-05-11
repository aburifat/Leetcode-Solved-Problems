class Solution {
    typedef long long ll;
public:
    int getAns(int ch, int ct, int n){
        if(ch>5)return 0;
        if(ct==n)return 1;
        int ans=0;
        for(int i=ch;i<5;i++){
            ans+=getAns(i,ct+1,n);
        }
        return ans;
    }
    int countVowelStrings(int n) {
        int ans=0;
        ans=getAns(0,0,n);
        return ans;
    }
};
