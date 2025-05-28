func findPeakElement(nums []int) int {
    siz := len(nums)
    if siz < 3 {
        if siz == 1 {
            return 0
        }
        if nums[0] < nums[1] {
            return 1
        }
        return 0
    }
    l, r := 0, siz - 1
    for l < r {
        mid := l + (r - l) / 2
        if (mid == 0 || nums[mid - 1] < nums[mid]) && (mid == siz - 1 || nums[mid] > nums[mid + 1]) {
            return mid
        } else if mid > 0 && nums[mid - 1] > nums[mid] {
            r = mid - 1
        } else {
            l = mid + 1
        }
    }
    return l
}
