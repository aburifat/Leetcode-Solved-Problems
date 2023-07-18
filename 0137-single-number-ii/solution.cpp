class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        vector<int>dgtct;
        int minus = 0;
        for(int i=0;i<len;i++){
            unsigned int tmp;
            if(nums[i]<0){
                minus++;
                minus%=3;
                tmp=-(unsigned int)nums[i];
            }else tmp = nums[i];
            int idx = 0;
            while(tmp){
                if(tmp&1){
                    while(dgtct.size()<=idx)dgtct.push_back(0);
                    dgtct[idx]++;
                    dgtct[idx]%=3;
                }
                idx++;
                tmp/=2;
            }
        }
        unsigned int val = 0;
        for(int i=(int)dgtct.size()-1;i>=0;i--){
            val*=2;
            if(dgtct[i]>0)val++;
        }
        int ans;
        if(minus)ans=-val;
        else ans = val;
        return ans;
    }
};
