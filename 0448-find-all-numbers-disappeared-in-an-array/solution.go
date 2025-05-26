func findDisappearedNumbers(nums []int) []int {
    ck := make([]bool, len(nums))

    for _, num := range nums {
        ck[num - 1] = true
    }

    i := 0
    for j, ok := range ck {
        if !ok {
            nums[i] = j + 1
            i++
        }
    }

    return nums[:i]
}
