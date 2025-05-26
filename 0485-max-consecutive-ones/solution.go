func findMaxConsecutiveOnes(nums []int) int {
    mx, curr := 0, 0
    for _, num := range nums {
        if num == 1 {
            curr++
        } else {
            curr = 0
        }

        if curr > mx {
            mx = curr
        }
    }

    return mx
}
