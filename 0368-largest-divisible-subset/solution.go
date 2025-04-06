func largestDivisibleSubset(nums []int) []int {
    n := len(nums)

    if n == 0 {
        return nums
    }

    sort.Ints(nums)

    nxt := make([]int, n)
    siz := make([]int, n)
    visited := make([]bool, n)

    for i := 0; i < n; i++ {
        nxt[i] = i
        siz[i] = 1
    }

    var solve func(idx int) int
    
    solve = func(idx int) int {
        if visited[idx] {
            return siz[idx]
        }

        for i := idx + 1; i < n; i++ {
            if nums[i] % nums[idx] == 0 {
                val := solve(i)
                if val + 1 > siz[idx] {
                    siz[idx] = val + 1
                    nxt[idx] = i
                }
            }
        }

        visited[idx] = true

        return siz[idx]
    }

    maxAns := 0
    maxIdx := -1

    for i := 0; i < n; i++ {
        tmp := solve(i)
        if tmp > maxAns {
            maxAns = tmp
            maxIdx = i
        }
    }

    result := []int{}

    for {
        result = append(result, nums[maxIdx])

        if nxt[maxIdx] == maxIdx {
            break
        }

        maxIdx = nxt[maxIdx]
    }

    return result
}
