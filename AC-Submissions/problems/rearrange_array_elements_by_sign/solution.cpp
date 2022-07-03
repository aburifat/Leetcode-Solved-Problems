class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int len=nums.size();
        vector<int>v(len,0);
        int idx=0;
        for(int i=0;i<len;i+=2){
            while(nums[idx]<0)idx++;
            v[i]=nums[idx];
            idx++;
        }
        idx=0;
        for(int i=1;i<len;i+=2){
            while(nums[idx]>0)idx++;
            v[i]=nums[idx];
            idx++;
        }
        return v;
    }
};