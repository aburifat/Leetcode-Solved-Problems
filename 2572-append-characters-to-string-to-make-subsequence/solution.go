func appendCharacters(s string, t string) int {
    ans, t_len, i := len(t), len(t), 0
    for _, ch := range s {
        if ch == rune(t[i]) {
            i++
            ans--
        }
        if i >= t_len {
            break
        }
    }
    return ans
}
