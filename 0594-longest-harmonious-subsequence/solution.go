func findLHS(nums []int) int {
    mp := map[int]int{}
    ans := 0
    for _, num := range nums {
        mp[num]++
        curr := mp[num]
        if val, ok := mp[num - 1]; ok {
            if (curr + val) > ans {
                ans = curr + val
            }
        }

        if val, ok := mp[num + 1]; ok {
            if curr + val > ans {
                ans = curr + val
            }
        }
    }

    return ans
}
