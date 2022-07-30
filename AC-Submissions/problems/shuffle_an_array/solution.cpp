class Solution {
public:
    vector<int>origin;
    vector<int>perm;
    Solution(vector<int>& nums) {
        origin=nums;
        perm=nums;
    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        int a=(rand()%perm.size());
        int b=(rand()%perm.size());
        swap(perm[a],perm[b]);
        return perm;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */