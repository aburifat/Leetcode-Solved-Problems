func fourSum(nums []int, target int) [][]int {
    var ans [][]int
    sort.Ints(nums)
    for i := 0; i < len(nums) - 3; i++ {
        if i > 0 && nums[i] == nums[i - 1] {
            continue
        }
        for j := i + 1; j < len(nums) - 2; j++ {
            if j > i + 1 && nums[j] == nums[j - 1] {
                continue
            }
            l := j + 1
            r := len(nums) - 1
            rem := target - nums[i] - nums[j]
            for l < r {
                if nums[l] + nums[r] < rem {
                    l++
                } else if nums[l] + nums[r] > rem {
                    r--
                } else {
                    ans = append(ans, []int{nums[i], nums[j], nums[l], nums[r]})
                    l++
                    r--
                    for l < r && nums[l] == nums[l - 1] {
                        l++
                    }
                    for l < r && nums[r] == nums[r + 1] {
                        r--
                    }
                }
            }
        }
    }
    
    return ans
}
