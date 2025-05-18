func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func threeSumClosest(nums []int, target int) int {
    ans := 100000
    sort.Ints(nums)
    for i := 0; i < len(nums); i++ {
        l := i + 1
        r := len(nums) - 1
        for l < r {
            val := nums[l] + nums[r] + nums[i]
            if val == target {
                return target
            } else {
                if abs(ans - target) > abs(val - target) {
                    ans = val
                }
                if val < target {
                    l++
                } else {
                    r--
                }
            }
        }
    }
    return ans
}
