class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        bool sign=true;
        int idx=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                idx=i;
                break;
            }
        }
        if(idx>=0&&idx<s.size()){
            if(s[idx]=='-'||s[idx]=='+'){
                if(s[idx]=='-')sign=false;
                idx++;
            }
        }
        for(int i=idx;i<s.size();i++){
            if(s[i]<'0'||s[i]>'9')break;
            if(sign&&ans>INT_MAX){
                break;
            }else if(!sign&&(-ans)<INT_MIN){
                break;
            }
            ans*=10;
            ans+=(s[i]-'0');
        }
        if(!sign)ans=-ans;
        if(ans>INT_MAX)ans=INT_MAX;
        else if(ans<INT_MIN)ans=INT_MIN;
        return ans;
    }
};