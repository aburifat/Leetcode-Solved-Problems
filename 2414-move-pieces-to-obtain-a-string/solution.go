func canChange(start string, target string) bool {
    slice := []rune(start)
    for i, j := len(target) - 1, len(target) - 1; i >= 0; i-- {
        if target[i] == 'R' {
            if slice[i] == 'L' {
                return false
            }
            if j > i {
                j = i
            }
            for j >= 0 {
                if (slice[j] == 'L') {
                    return false
                } else if (slice[j] == 'R') {
                    slice[i], slice[j] = slice[j], slice[i]
                    break
                }
                j--
            }
        }
    }
    for i, j := 0, 0; i < len(target); i++ {
        if target[i] == 'L' {
            if slice[i] == 'R' {
                return false
            }
            if j < i {
                j = i
            }
            for j < len(target) {
                if (slice[j] == 'R') {
                    return false
                } else if (slice[j] == 'L') {
                    slice[i], slice[j] = slice[j], slice[i]
                    break
                }
                j++
            }
        }
    }
    for i := 0; i < len(target); i++ {
        if slice[i] != rune(target[i]) {
            return false
        }
    }
    return true
}
