func checkEqualPartitions(nums []int, target int64) bool {
    n := len(nums)
    minMask := 0
    maxMask := 1 << n

    for mask := minMask + 1; mask < maxMask; mask++ {
        prod1, prod2 := 1, 1
        for i := 0; i < n; i++ {
            if ((mask >> i) & 1) == 1 {
                prod1 *= nums[i]
            } else {
                prod2 *= nums[i]
            }
        }

        if prod1 == prod2 && int64(prod1) == target {
            return true
        }
    }

    return false
}
