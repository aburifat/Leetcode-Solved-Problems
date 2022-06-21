class KthLargest {
    priority_queue<int,vector<int>,greater<int>>pq;
    int mx;
public:
    KthLargest(int k, vector<int>& nums) {
        mx=k;
        while(!pq.empty())pq.pop();
        int len=nums.size();
        for(int i=0;i<len;i++){
            pq.push(nums[i]);
            if(pq.size()>k)pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>mx)pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
