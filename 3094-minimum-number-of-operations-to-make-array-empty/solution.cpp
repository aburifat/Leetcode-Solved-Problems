class Solution {
public:
    int minOperations(vector<int>& nums) {
        int len = nums.size();
        set<int>s;
        unordered_map<int,int>mp;
        for(int i=0;i<len;i++){
            s.insert(nums[i]);
            mp[nums[i]]++;
        }
        
        bool ck = true;
        int ans = 0;
        for(auto it = s.begin(); it != s.end(); it++){
            int val = *it;
            int ct = mp[val];
            if(ct==1){
                ck=false;
                break;
            }
            ans += ((ct/3) + (ct%3!=0));
        }

        if(!ck)ans=-1;
        return ans;
    }
};
