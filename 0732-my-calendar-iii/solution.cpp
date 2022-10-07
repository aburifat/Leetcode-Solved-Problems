class MyCalendarThree {
    set<int>point;
    map<int,int>count;
public:
    MyCalendarThree() {
        point.clear();
        count.clear();
    }
    
    int book(int start, int end) {
        point.insert(start);
        point.insert(end);
        count[start]++;
        count[end]--;
        int ans=0;
        int val=0;
        for(auto it=point.begin();it!=point.end();it++){
            val+=count[*it];
            ans=max(ans,val);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
