class Solution {
public:
    int s2i(string s){
        int len=s.size();
        int val=0;
        for(int i=0;i<len;i++){
            if(s[i]>='0'&&s[i]<='9'){
                int tmp=s[i]-'0';
                val*=10;
                val+=tmp;
            }
        }
        if(len>0&&s[0]=='-')val=-val;
        return val;
    }
    int evalRPN(vector<string>& tokens) {
        int len=tokens.size();
        stack<int>s;
        for(int i=0;i<len;i++){
            if(tokens[i].size()==1&&(tokens[i][0]=='+'||tokens[i][0]=='-'||tokens[i][0]=='*'||tokens[i][0]=='/')){
                int a,b;
                if(!s.empty()){
                    b=s.top();
                    s.pop();
                }
                if(!s.empty()){
                    a=s.top();
                    s.pop();
                }
                if(tokens[i][0]=='+'){
                    s.push((long long)a+(long long)b);
                }else if(tokens[i][0]=='-'){
                    s.push(a-b);
                }else if(tokens[i][0]=='*'){
                    s.push((long long)a*(long long)b);
                }else{
                    s.push(a/b);
                }
            }else{
                //cout<<s2i(tokens[i])<<endl;
                s.push(s2i(tokens[i]));
            }
        }
        int ans;
        if(!s.empty()){
            ans=s.top();
            s.pop();
        }
        return ans;
    }
};