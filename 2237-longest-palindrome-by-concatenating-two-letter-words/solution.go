func WordToInt(word string) int {
    c1 := int(word[0]) - int('a')
    c2 := int(word[1]) - int('a')
    return c1 * 26 + c2
}

func minInt(a int, b int) int {
    if a < b {
        return a
    }

    return b
}

func longestPalindrome(words []string) int {
    mx := 26 * 26
    ct := make([]int, mx)

    for _, w := range words {
        idx := WordToInt(w)
        ct[idx]++
    }

    ans := 0
    oddCnt := 0
    for i := 0; i < 26; i++ {
        idx := 26 * i + i

        if ct[idx] % 2 == 0 {
            ans += 2 * ct[idx]
        } else {
            oddCnt++
            ans += 2 * (ct[idx] - 1)
        }
    }

    if (oddCnt > 0) {
        ans += 2
    }

    for i := 0 ; i < 26; i++ {
        for j := i + 1; j < 26; j++ {
            idx1 := i * 26 + j
            idx2 := j * 26 + i
            v := minInt(ct[idx1], ct[idx2])
            ans += v * 4
        }
    }

    return ans
}
