func twoSum(nums []int, target int) []int {
    mp := make(map[int]int)
    for j, num := range nums {
        if i, ok := mp[target - num]; ok {
            return []int{i, j}
        }
        mp[num] = j
    }
    return []int{-1, -1}
}
