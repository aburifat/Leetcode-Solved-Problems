func smallestEquivalentString(s1 string, s2 string, baseStr string) string {
    parent := make([]int, 26)
    for i := 0; i < 26; i++ {
        parent[i] = i
    }

    var finder func(val int) int
    finder = func(val int) int {
        if parent[val] != val {
            parent[val] = finder(parent[val])
        }
        return parent[val]
    }

    union := func(a, b int) {
        a, b = finder(a), finder(b)
        if a != b {
            if a < b {
                parent[b] = a
            } else {
                parent[a] = b
            }
        }
    }

    for i := 0; i < len(s1); i++ {
        union(int(s1[i] - 'a'), int(s2[i] - 'a'))
    }

    sb := make([]byte, len(baseStr))

    for i := 0; i < len(baseStr); i++ {
        sb[i] = byte(finder(int(baseStr[i] - 'a')) + 'a')
    }

    return string(sb)
}
