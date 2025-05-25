import "math"

func Max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func maxProduct(nums []int) int {
    pre, suff, siz, ans := 1, 1, len(nums), math.MinInt64
    for i := 0; i < siz; i++ {
        if pre == 0 {
            pre = 1
        }
        if suff == 0 {
            suff = 1
        }
        pre *= nums[i]
        suff *= nums[siz - i - 1]
        ans = Max(ans, Max(pre, suff))
    }

    return ans
}
