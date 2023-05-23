class KthLargest {
    vector<int>v;
    int idx;
public:
    KthLargest(int k, vector<int>& nums) {
        v=nums;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        idx = k-1;
    }
    
    int add(int val) {
        if(idx<(int)v.size()&&v[idx]>=val)return v[idx];
        else{
            for(int i=0;i<=min(idx,(int)v.size()-1);i++){
                if(val>v[i])swap(v[i],val);
            }
            v.push_back(val);
        }
        return v[idx];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
