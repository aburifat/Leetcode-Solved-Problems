func minOperations(nums []int, k int) int {
    ct := make([]int, 101);
    ans := 0
    for i := 0; i < len(nums); i++ {
        if nums[i] < k {
            return -1;
        } else if nums[i] == k {
            continue;
        } else {
            if ct[nums[i]] == 0 {
                ans++
            }
            ct[nums[i]]++
        }
    }
    return ans
}
