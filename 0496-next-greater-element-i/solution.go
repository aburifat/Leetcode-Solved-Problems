func nextGreaterElement(nums1 []int, nums2 []int) []int {
    stack := []int{}
    nextGreater := make(map[int]int)

    for i := len(nums2) - 1; i >= 0; i -- {
        for len(stack) > 0 && nums2[i] > stack[len(stack) - 1] {
            stack = stack[:len(stack) - 1]
        }

        if len(stack) > 0 {
            nextGreater[nums2[i]] = stack[len(stack) - 1]
        } else {
            nextGreater[nums2[i]] = -1
        }

        stack = append(stack, nums2[i])
    }

    for i := 0; i < len(nums1); i++ {
        nums1[i] = nextGreater[nums1[i]]
    }

    return nums1
}
