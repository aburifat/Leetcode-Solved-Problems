func maxKDivisibleComponents(n int, edges [][]int, values []int, k int) int {
    tree := make([][]int, n)
    for _, edge := range edges {
        tree[edge[0]] = append(tree[edge[0]], edge[1])
        tree[edge[1]] = append(tree[edge[1]], edge[0])
    }
    ans := 0
    var solve func(node, parent int) int
    solve = func(node, parent int) int {
        sum := values[node]
        for _, adj := range tree[node] {
            if adj != parent {
                sum += solve(adj, node)
            }
        }
        sum %= k
        if sum == 0 {
            ans++
        }
        return sum
    }
    solve(0, -1)
    return ans
}
