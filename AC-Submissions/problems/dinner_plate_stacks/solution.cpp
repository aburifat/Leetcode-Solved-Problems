class DinnerPlates {
    int len;
    map<int,vector<int>>mp;
    set<int>nxt;
public:
    DinnerPlates(int capacity) {
        len=capacity;
    }
    
    void push(int val) {
        if(nxt.empty()){
            nxt.insert(mp.size());
        }
        int idx=*nxt.begin();
        mp[idx].push_back(val);
        if(mp[idx].size()==len){
            nxt.erase(idx);
        }
    }
    
    int pop() {
        while(!mp.empty()&&mp.rbegin()->second.empty()){
            mp.erase(mp.rbegin()->first);
        }
        if(mp.empty())return -1;
        return popAtStack(mp.rbegin()->first);
    }
    
    int popAtStack(int index) {
        if(mp.find(index)!=mp.end()){
            if(!mp[index].empty()){
                int val=mp[index][mp[index].size()-1];
                mp[index].pop_back();
                nxt.insert(index);
                return val;
            }else return -1;
        }else return -1;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */