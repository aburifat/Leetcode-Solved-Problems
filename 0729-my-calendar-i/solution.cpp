class MyCalendar {
public:
    vector<pair<int,int>>v;
    MyCalendar() {
        v.clear();
    }
    
    bool book(int start, int end) {
        bool ck=true;
        for(int i=0;i<v.size();i++){
            if((start>=v[i].first&&start<=v[i].second)||(end-1>=v[i].first&&end-1<=v[i].second)){
                ck=false;
                break;
            }else if((start<=v[i].first&&end-1>=v[i].second)||(start>=v[i].first&&end-1<=v[i].second)){
                ck=false;
                break;
            }
        }
        if(ck)v.push_back({start,end-1});
        return ck;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
