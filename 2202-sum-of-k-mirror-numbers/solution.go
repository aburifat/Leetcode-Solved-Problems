func kMirror(k int, n int) int64 {
    digit := make([]int, 100)
    left, count, ans := 1, 0, int64(0)

    for count < n {
        right := left * 10
        for op := 0; op < 2; op++ {
            for pref := left; pref < right && count < n; pref++ {
                comb := int64(pref)
                suff:= pref
                if op == 0 {
                    suff /= 10
                }
                for suff > 0 {
                    comb = comb * 10 + int64(suff % 10)
                    suff /= 10
                }
                if isPalindrome(comb, k, digit) {
                    count++
                    ans += comb
                }
            }
        }
        left = right
    }

    return ans
}

func isPalindrome(num int64, k int, digit []int) bool {
    length := -1
    for num > 0 {
        length++
        digit[length] = int(num % int64(k))
        num /= int64(k)
    }

    for i, j := 0, length; i < j; i, j = i + 1, j - 1 {
        if digit[i] != digit[j] {
            return false
        }
    }

    return true
}
