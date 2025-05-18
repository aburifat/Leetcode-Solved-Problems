func removeDuplicates(nums []int) int {
    idx := 1
    for i := 1; i < len(nums); i++ {
        if nums[i] != nums[i - 1] {
            nums[idx] = nums[i]
            idx++
        }
    }
    return idx
}
