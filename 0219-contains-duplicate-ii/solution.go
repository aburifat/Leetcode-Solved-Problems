func containsNearbyDuplicate(nums []int, k int) bool {
    mp := map[int]int{}
    for idx, num := range nums {
        if val, ok := mp[num]; ok && idx - val <= k {
            return true
        }
        mp[num] = idx
    }
    return false
}
