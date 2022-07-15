class Solution {
public:
    bool isPalindrome(string s) {
        vector<char>v;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z')v.push_back(s[i]);
            else if(s[i]>='A'&&s[i]<='Z')v.push_back(s[i]-'A'+'a');
            else if(s[i]>='0'&&s[i]<='9')v.push_back(s[i]);
        }
        for(int i=0,j=v.size()-1;i<j;i++,j--){
            if(v[i]!=v[j])return false;
        }
        return true;
    }
};