import "fmt"

func search(nums []int, target int) bool {
    l, r := 0 , len(nums) - 1

    for l <= r {
        for l < r && nums[l] == nums[r] {
            r--
        }
        mid := l + (r - l) / 2
        if nums[mid] == target || nums[l] == target || nums[r] == target {
            return true
        }
        if nums[l] <= nums[mid] {
            if target < nums[mid] && nums[l] < target {
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

    return false
}
