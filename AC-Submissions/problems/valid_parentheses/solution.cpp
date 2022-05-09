class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        char openings[]={'(','{','['};
        char closings[]={')','}',']'};
        map<char,int>openMp,closeMp;
        for(int i=0;i<3;i++)openMp[openings[i]]=i+1;
        for(int i=0;i<3;i++)closeMp[closings[i]]=i+1;
        int ck=0;
        int len=s.size();
        for(int i=0;i<len;i++){
            char tmp=s[i];
            if(openMp[tmp])st.push(tmp);
            else{
                int idx=closeMp[tmp]-1;
                tmp=openings[idx];
                if(st.empty()){
                    ck=1;
                    break;
                }
                if(tmp==st.top())st.pop();
                else{
                    ck=1;
                    break;
                }
            }
        }
        if(!st.empty())ck=1;
        if(ck)return false;
        else return true;
    }
};