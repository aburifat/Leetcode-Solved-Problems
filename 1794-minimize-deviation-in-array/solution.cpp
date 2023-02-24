class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int len=nums.size();
        priority_queue<int>pq;
        int mn=INT_MAX;
        for(int i=0;i<len;i++){
            if(nums[i]%2!=0)nums[i]*=2;
            pq.push(nums[i]);
            mn=min(mn,nums[i]);
        }
        int ans=INT_MAX;
        while(!pq.empty()){
            int val=pq.top();
            ans=min(ans,abs(mn-val));
            pq.pop();
            if(val%2==0){
                val/=2;
                mn=min(mn,val);
                pq.push(val);
            }else break;
        }
        return ans;
    }
};
