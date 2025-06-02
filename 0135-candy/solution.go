func candy(ratings []int) int {
    n := len(ratings)

    inDegree := make([]int, n)
    adj := make([][]int, n)

    for i := 0; i < n; i++ {
        if i > 0 && ratings[i - 1] > ratings[i] {
            adj[i] = append(adj[i], i - 1)
            inDegree[i - 1]++
        }
        if i < n - 1 && ratings[i] < ratings[i + 1] {
            adj[i] = append(adj[i], i + 1)
            inDegree[i + 1]++
        }
    }

    q := make([]int, 0)

    for i := 0; i < n; i++ {
        if inDegree[i] == 0 {
            q = append(q, i)
        }
    }

    sum := 0
    cnt := make([]int, n)

    for len(q) > 0 {
        node := q[0]
        q = q[1:]

        if cnt[node] == 0 {
            cnt[node] = 1
        }

        sum += cnt[node]

        for _, next := range adj[node] {
            inDegree[next]--
            cnt[next] = cnt[node] + 1

            if inDegree[next] == 0 {
                q = append(q, next)
            }
        }
    }

    return sum
}
