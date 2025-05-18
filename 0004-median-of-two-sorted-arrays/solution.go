func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    siz := len(nums1) + len(nums2)
    res := make([]int, siz)
    i, j, k := 0, 0, 0
    for i < len(nums1) && j < len(nums2) {
        if nums1[i] <= nums2[j] {
            res[k] = nums1[i]
            i = i + 1
        } else {
            res[k] = nums2[j]
            j = j + 1
        }
        k = k + 1
    }

    for ; i < len(nums1); i = i + 1 {
        res[k] = nums1[i]
        k = k + 1
    }

    for ; j < len(nums2); j = j + 1 {
        res[k] = nums2[j]
        k = k + 1
    }
    ans := 0.
    idx := siz / 2
    if (siz % 2 == 0) {
        ans = float64(res[idx - 1] + res[idx]) / 2.0
    } else {
        ans = float64(res[idx])
    }

    return ans
}
