func findWords(words []string) []string {
    patt := "qwertyuiop#asdfghjkl#zxcvbnm"
    mp := map[rune]int{}
    ans := []string{}
    col := 1
    for _, ch := range patt {
        if ch == '#' {
            col++
            continue
        }
        mp[ch] = col
        mp[ch - 'a' + 'A'] = col
    }

    for _, word := range words {
        valid := true
        for i := 1; i < len(word); i++ {
            if mp[rune(word[i - 1])] != mp[rune(word[i])] {
                valid = false
                break
            }
        }
        if valid {
            ans = append(ans, word)
        }
    }

    return ans
}
