class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        bool arr[n+1];
        memset(arr,false,sizeof(arr));
        int dbl;
        for(int i=0;i<n;i++){
            if(arr[nums[i]]==true)dbl = nums[i];
            arr[nums[i]]=true;
        }
        vector<int>ans;
        ans.push_back(dbl);
        for(int i=1;i<=n;i++){
            if(arr[i]==false){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
