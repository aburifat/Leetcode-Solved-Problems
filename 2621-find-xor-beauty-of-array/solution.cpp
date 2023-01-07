class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int ors=0;
        int len=nums.size();
        for(int i=0;i<len;i++){
            ors|=nums[i];
        }
        int ans;
        for(int i=0;i<len;i++){
            if(i==0)ans=(ors&nums[i]);
            else ans^=(ors&nums[i]);
        }
        return ans;
    }
};
