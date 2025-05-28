func sortColors(nums []int)  {
    idx, siz := 0, len(nums)
    for i := 1; i < siz; i++ {
        if nums[i] == 0 {
            for idx <= i && nums[idx] == 0 {
                idx++
            }
            if idx < i {
                nums[idx], nums[i] = nums[i], nums[idx]
            }
        }
    }
    idx = siz - 1
    for i := siz - 2; i >= 0; i-- {
        if nums[i] == 2 {
            for idx >= i && nums[idx] == 2 {
                idx--
            }
            if idx > i {
                nums[idx], nums[i] = nums[i], nums[idx]
            }
        }
    }
}
