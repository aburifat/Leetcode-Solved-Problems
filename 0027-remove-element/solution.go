func removeElement(nums []int, val int) int {
    idx, ct := 0, 0
    for i := 0; i < len(nums); i++ {
        if nums[i]!= val {
            nums[idx] = nums[i]
            idx++
            ct++
        }
    }
    return ct
}
