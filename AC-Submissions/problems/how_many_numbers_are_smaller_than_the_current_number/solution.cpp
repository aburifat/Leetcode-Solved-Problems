class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>nn=nums;
        sort(nn.begin(),nn.end());
        vector<int>ans;
        int ct[110];
        for(int i=0;i<110;i++)ct[i]=-1;
        int len=nn.size();
        for(int i=0;i<len;i++){
            if(ct[nn[i]]==-1){
                ct[nn[i]]=i;
            }
        }
        for(int i=0;i<len;i++)ans.push_back(ct[nums[i]]);
        return ans;
    }
};