func maxCount(banned []int, n int, maxSum int) int {
    slices.Sort(banned)
    idx, ct := 0, 0
    for i := 1; i <= n; i++ {
        for idx < len(banned) && banned[idx] < i {
            idx++
        }
        if idx < len(banned) && banned[idx] == i {
            continue
        } else {
            maxSum -= i
            if maxSum >= 0 {
                ct++
            } else {
                break
            }
        }
    }
    return ct
}
