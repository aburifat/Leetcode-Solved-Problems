class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            int curr=0;
            string newS="";
            int ct=0;
            for(int i=0;i<s.size();i++){
                ct++;
                curr+=(s[i]-'0');
                if((ct==k)||(i==(s.size()-1))){
                    ct=0;
                    newS+=to_string(curr);
                    curr=0;
                }
            }
            s=newS;
        }
        return s;
    }
};
