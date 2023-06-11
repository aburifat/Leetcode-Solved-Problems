class SnapshotArray {
public:
    int snaped;
    vector<vector<pair<int,int>>>mem;
    SnapshotArray(int length) {
        snaped = 0;
        mem.assign(length,vector<pair<int,int>>(1,{0,0}));
    }
    
    void set(int index, int val) {
        int len = mem[index].size();
        if(len==0)mem[index].push_back({snaped,val});
        else if(mem[index][len-1].first==snaped)mem[index][len-1].second=val;
        else mem[index].push_back({snaped,val});
    }
    
    int snap() {
        snaped++;
        return snaped-1;
    }
    
    int get(int index, int snap_id) {
        int l=0;
        int r=mem[index].size()-1;
        int pos = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(mem[index][mid].first<=snap_id){
                pos=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return mem[index][pos].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
