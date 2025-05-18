func threeSum(nums []int) [][]int {
    var ans [][]int
    ct := make([]int, 200010)
    inc := int(1e5)
    var v []int
    siz := len(nums)

    for i := 0; i < siz; i++ {
        if ct[nums[i] + inc] == 0 {
            v = append(v, nums[i])
        }
        ct[nums[i] + inc]++
    }

    sort.Ints(v)
    siz = len(v)

    if ct[inc] > 2 {
        ans = append(ans, []int{0, 0, 0})
    }

    if ct[inc] != 0 {
        ct[inc] = 1
        for i := 0; i < siz; i++ {
            if v[i] >= 0 {
                break
            }
            if ct[-v[i] + inc] != 0 {
                ans = append(ans, []int{0, v[i], -v[i]})
            }
        }
        ct[inc] = 0
    }

    for i := 0; i < siz; i++ {
        if ct[v[i] + inc] > 1 {
            val := -(2 * v[i])
            if val >= -inc && val <= inc && ct[val + inc] != 0 {
                ans = append(ans, []int{v[i], v[i], val})
            }
            ct[v[i] + inc] = 1
        }
    }

    for i := 0; i < siz; i++ {
        if v[i] == 0 || ct[v[i] + inc] == 0 {
            continue
        }
        ct[v[i] + inc] = 0
        for j := i + 1; j < siz; j++ {
            val := - (v[i] + v[j])
            if v[j] == 0 || val == 0 {
                continue
            }
            if val < v[j] {
                continue
            }
            if val != v[i] && val != v[j] {
                if val >= -inc && val <= inc && ct[val + inc] != 0 {
                    ans = append(ans, []int{v[i], v[j], val})
                }
            }
        }
    }
    return ans
}
