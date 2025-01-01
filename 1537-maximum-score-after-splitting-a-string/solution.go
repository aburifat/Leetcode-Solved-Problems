func maxScore(s string) int {
    curr := 0
    for _, ch := range s {
        if ch == '1' {
            curr++
        }
    }
    ans := 0
    for i := 0; i < len(s) - 1; i++ {
        if s[i] == '0' {
            curr++
        } else {
            curr--
        }
        if ans < curr {
            ans = curr
        }
    }
    return ans
}
