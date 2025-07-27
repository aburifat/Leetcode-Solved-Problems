func countHillValley(nums []int) int {
    idx, ans := 0, 0
    for i := 1; i < len(nums); i++ {
        if nums[idx] != nums[i] {
            idx++
            nums[idx] = nums[i]
        }
    }

    nums = nums[:idx+1]

    for i := 2; i < len(nums); i++ {
        if nums[i - 2] > nums[i - 1] && nums[i - 1] < nums[i] {
            ans++
        } else if nums[i - 2] < nums[i - 1] && nums[i - 1] > nums[i] {
            ans++
        }
    }

    return ans
}
