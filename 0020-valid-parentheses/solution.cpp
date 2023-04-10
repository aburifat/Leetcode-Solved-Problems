class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        stack<char>st;
        for(int i=0;i<len;i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')st.push(s[i]);
            else{
                if(st.empty())return false;
                if(s[i]==')'){
                    if(st.top()=='(')st.pop();
                    else break;
                }
                else if(s[i]=='}'){
                    if(st.top()=='{')st.pop();
                    else break;
                }
                else{
                    if(st.top()=='[')st.pop();
                    else break;
                }
            }
        }
        if(st.empty())return true;
        return false;
    }
};
