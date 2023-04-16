class FreqStack {
    int MX=2e4+10;
    int mx_ct;
    unordered_map<int,int>count;
    vector<vector<int>>stacks;
public:
    FreqStack() {
        mx_ct=0;
        count.clear();
        stacks.clear();
    }
    
    void push(int val) {
        count[val]++;
        if(count[val]>mx_ct){
            mx_ct=count[val];
            while((int)stacks.size()<=mx_ct)stacks.push_back(vector<int>());
        }
        stacks[count[val]].push_back(val);
    }
    
    int pop() {
        if(stacks[mx_ct].size()==0)mx_ct--;
        int siz = stacks[mx_ct].size();
        int val = stacks[mx_ct][siz-1];
        count[val]--;
        stacks[mx_ct].pop_back();
        return val;
    }
};
