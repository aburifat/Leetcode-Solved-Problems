class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int len=nums.size();
        vector<int>myNums=nums;
        vector<long long>left;
        for(int i=0;i<myNums.size();i++){
            if(i==0)left.push_back(myNums[0]);
            else left.push_back(myNums[i]+left[i-1]);
        }
        reverse(myNums.begin(),myNums.end());
        vector<long long>right;
        for(int i=0;i<myNums.size();i++){
            if(i==0)right.push_back(myNums[0]);
            else right.push_back(myNums[i]+right[i-1]);
        }
        int ans=INT_MAX;
        int idx=lower_bound(right.begin(),right.end(),x)-right.begin();
        if(idx>=0&&idx<right.size()){
            if(right[idx]==x)ans=min(ans,idx+1);
        }
        for(int i=0;i<left.size();i++){
            int val=x-left[i];
            if(val==0)ans=min(ans,i+1);
            else if(val<0)break;
            else{
                idx=lower_bound(right.begin(),right.end(),val)-right.begin();
                if(idx>=0&&idx<right.size()){
                    if(right[idx]==val&&(idx+1+i+1<=len))ans=min(ans,idx+1+i+1);
                }
            }
        }
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};
