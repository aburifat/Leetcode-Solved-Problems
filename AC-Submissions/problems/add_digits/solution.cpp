class Solution {
public:
    int addDigits(int num) {
        string s=to_string(num);
        while(s.size()>1){
            int len=s.size();
            int val=0;
            for(int i=0;i<len;i++){
                val+=(s[i]-'0');
            }
            s=to_string(val);
        }
        return s[0]-'0';
    }
};