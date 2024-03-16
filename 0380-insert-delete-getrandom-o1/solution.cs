public class RandomizedSet {
    private List<int> nums;
    private Dictionary<int,int> idxMap;
    private Random random;
    public RandomizedSet() {
        nums = new();
        idxMap = new();
        random = new();
    }
    
    public bool Insert(int val) {
        if(idxMap.ContainsKey(val)) return false;
        nums.Add(val);
        idxMap.Add(val, nums.Count - 1);
        return true;
    }
    
    public bool Remove(int val) {
        if(!idxMap.ContainsKey(val)) return false;
        int idx = idxMap[val];
        nums[idx] = nums[nums.Count - 1];
        idxMap[nums[idx]] = idx;
        nums.RemoveAt(nums.Count - 1);
        idxMap.Remove(val);
        return true;
    }
    
    public int GetRandom() {
        int idx = random.Next(nums.Count);
        return nums[idx];
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.Insert(val);
 * bool param_2 = obj.Remove(val);
 * int param_3 = obj.GetRandom();
 */
