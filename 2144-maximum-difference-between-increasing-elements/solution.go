func maximumDifference(nums []int) int {
    min, dif := int(1e9 + 5), -1
    for _, num := range nums {
        val := num - min
        if min < num && dif < val {
            dif = val
        } else if min > num {
            min = num
        }
    }

    return dif
}
