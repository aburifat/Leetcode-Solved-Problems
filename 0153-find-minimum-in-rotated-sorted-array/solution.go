import "math"

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func findMin(nums []int) int {
    l, r, ans := 0, len(nums) - 1, math.MaxInt64
    for l <= r {
        mid := l + (r - l) / 2
        ans = min(ans, min(nums[l], min(nums[r], nums[mid])))
        if nums[l] < nums[mid] && nums[mid] < nums[r] {
            break;
        }
        if nums[l] < nums[mid] {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }
    return ans
}
