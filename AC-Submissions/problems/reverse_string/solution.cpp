class Solution {
public:
    void reverseString(vector<char>& s) {
        int len=s.size();
        vector<char>v=s;
        for(int i=0,j=len-1;i<len;i++,j--){
            s[i]=v[j];
        }
        
    }
};