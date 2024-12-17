func repeatLimitedString(s string, repeatLimit int) string {
    ct := make([]int, 26)
    for _, ch := range s {
        ct[ch-'a']++
    }

    ans := make([]rune, 0, len(s))
    curr, next, idx := 25, 24, 0
    
    for curr >= 0 {
        if ct[curr] == 0 {
            curr--
            next = curr - 1
            continue
        }

        count := min(repeatLimit, ct[curr])
        ct[curr] -= count

        for count > 0 {
            ans = append(ans, rune('a' + curr))
            idx++
            count--
        }

        if ct[curr] > 0 {
            for next >= 0 && ct[next] == 0 {
                next--
            }
            if next < 0 {
                break
            }
            ans = append(ans, rune('a' + next))
            idx++
            ct[next]--
        }
    }

    return string(ans)
}
