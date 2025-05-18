func search(nums []int, target int) int {
    l, r := 0, len(nums) - 1

    if r == 0 {
        if nums[0] == target {
            return 0
        }
        return -1
    }

    for l < r {
        if nums[l] == target {
            return l
        } else if nums[r] == target {
            return r
        }
        mid := l + (r - l) / 2;
        if nums[mid] == target {
            return mid
        }
        if nums[l] < nums[mid] {
            if nums[l] < target && target < nums[mid] {
                r = mid - 1
            } else {
                l = mid + 1
            }
        } else {
            if nums[mid] < target && target < nums[r] {
                l = mid + 1
            } else {
                r = mid - 1
            }
        }
    }

    return -1
}
