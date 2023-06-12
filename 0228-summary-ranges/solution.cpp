class Solution {
public:
    string print(int l, int r){
        string s="";
        s+=to_string(l);
        if(l!=r){
            s+="->";
            s+=to_string(r);
        }
        return s;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        int l,r;
        vector<string>ans;
        for(int i=0;i<len;i++){
            if(i==0){
                l=nums[i];
                r=nums[i];
            }else{
                if(nums[i]==nums[i-1]+1){
                    r=nums[i];
                }else{
                    ans.push_back(print(l,r));
                    l=nums[i];
                    r=nums[i];
                }
            }
            if(i==len-1){
                ans.push_back(print(l,r));
            }
        }
        return ans;
    }
};
