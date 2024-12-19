func maxChunksToSorted(arr []int) int {
    left, mn, mx, ans := 0, 10, 0, 0
    for idx, val:= range arr {
        mn, mx = min(mn, val), max(mx, val)
        if mn == left && mx == idx {
            left, mn, mx, ans = idx + 1, 10, 0, ans + 1
        }
    }
    return ans
}
