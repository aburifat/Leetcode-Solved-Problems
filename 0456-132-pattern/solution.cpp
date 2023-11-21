class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int len = nums.size();
        int mid = INT_MIN;
        int mx[len];
        int idx=-1;
        mx[++idx] = nums[len-1];
        for(int i=len-2;i>=0;i--){
            if(nums[i]<mid)return true;
            while(idx>-1&&mx[idx]<nums[i]){
                mid = mx[idx--];
            }
            mx[++idx]=nums[i];
        }
        return false;
    }
};
