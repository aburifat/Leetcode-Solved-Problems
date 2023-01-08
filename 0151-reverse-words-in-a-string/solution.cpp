class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string tmp;
        stack<string>st;
        while(is>>tmp){
            st.push(tmp);
        }
        string ans="";
        bool ck=false;
        while(!st.empty()){
            if(!ck)ck=true;
            else ans+=" ";
            tmp=st.top();
            ans+=tmp;
            st.pop();
        }
        return ans;
    }
};
