class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        stack<int>st;
        vector<int>v;
        for(int i=0;i<(int)s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                if(!st.empty()){
                    v.push_back(st.top());
                    v.push_back(i);
                    st.pop();
                }
            }
        }
        sort(v.begin(),v.end());
        int ct=0;
        int ck=0;
        for(int i=0;i<(int)v.size();i++){
            if(!ck){
                ct++;
                ck++;
            }
            else{
                if(v[i]-1==v[i-1])ct++;
                else{
                    ans=max(ans,ct);
                    ct=1;
                    ck=0;
                }
            }
            if(i==(int)v.size()-1)ans=max(ans,ct);
        }
        return ans;
    }
};
