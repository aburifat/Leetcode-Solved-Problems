import "math"

func thirdMax(nums []int) int {
    max := [3]int{math.MinInt, math.MinInt, math.MinInt}

    for _, num := range nums {
        for i := 0; i < 3; i++ {
            if max[i] == num {
                break
            }
            if max[i] < num {
                num, max[i] = max[i], num
            }
        }
    }

    if max[2] != math.MinInt {
        return max[2]
    }

    return max[0]
}
