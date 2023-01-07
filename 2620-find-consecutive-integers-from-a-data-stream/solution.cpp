class DataStream {
    int key;
    int count;
    int ct=0;
public:
    DataStream(int value, int k) {
        key=value;
        count=k;
    }
    
    bool consec(int num) {
        if(num==key){
            ct++;
        }else{
            ct=0;
        }
        if(ct>=count)return true;
        else return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
