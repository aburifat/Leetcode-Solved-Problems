class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int>hashMap;
        for(auto u:nums)hashMap[u]++;
        while(!hashMap.empty()){
            int l=hashMap.begin()->first;
            for(int i=0;i<k;i++){
                if(hashMap.find(l)==hashMap.end())return false;
                hashMap[l]--;
                if(!hashMap[l])hashMap.erase(l);
                l++;
            }
        }
        return true;
    }
};