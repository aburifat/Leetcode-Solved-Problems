class MinStack {
    stack<pair<int,int>>st;
    int mn=INT_MAX;
public:
    MinStack() {
        while(!st.empty())st.pop();
        mn=INT_MAX;
    }
    
    void push(int val) {
        mn=min(mn,val);
        st.push({val,mn});
    }
    
    void pop() {
        st.pop();
        if(st.empty())mn=INT_MAX;
        else mn=st.top().second;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */