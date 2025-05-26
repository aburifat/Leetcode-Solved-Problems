func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}

func findPoisonedDuration(timeSeries []int, duration int) int {
    ans := duration
    for i := 1; i < len(timeSeries); i++ {
        ans += min(duration, timeSeries[i] - timeSeries[i - 1])
    }
    return ans
}
