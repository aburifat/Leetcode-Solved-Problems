class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int push_len = pushed.size();
        int pop_len = popped.size();
        int idx = 0;
        for(int i=0;i<push_len;i++){
            st.push(pushed[i]);
            if(idx>=pop_len)break;
            while(!st.empty()&&st.top()==popped[idx]){
                st.pop();
                idx++;
            }
        }
        if(st.empty())return true;
        return false;
    }
};