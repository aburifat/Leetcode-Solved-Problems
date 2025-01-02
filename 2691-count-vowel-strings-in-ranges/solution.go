func isVowel(ch byte) bool {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
}

func vowelStrings(words []string, queries [][]int) []int {
    ct := make([]int, len(words))
    for idx, word := range words {
        if isVowel(word[0]) == true && isVowel(word[len(word) - 1]) == true {
            ct[idx] = 1
        }
    }
    for i := 1; i < len(ct); i++ {
        ct[i] += ct[i - 1]
    }

    ans := make([]int, len(queries))

    for idx, query := range queries {
        ans[idx] = ct[query[1]]
        if query[0] != 0 {
            ans[idx] -= ct[query[0] - 1]
        }
    }

    return ans
}
