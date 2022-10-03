class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<char>v;
        for(int i=0;i<s.size();i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
                v.push_back(s[i]);
            }
        }
        reverse(v.begin(),v.end());
        int idx=0;
        for(int i=0;i<s.size();i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
                s[i]=v[idx];
                idx++;
            }
        }
        return s;
    }
};