class SmallestInfiniteSet {
    int mn;
    set<int>ex;
public:
    SmallestInfiniteSet() {
        mn=1;
        ex.clear();
    }
    
    int popSmallest() {
        int val;
        if(ex.size()!=0){
            val=*ex.begin();
            ex.erase(ex.begin());
        }else{
            val=mn;
            mn++;
        }
        return val;
    }
    
    void addBack(int num) {
        if(num<mn)ex.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
