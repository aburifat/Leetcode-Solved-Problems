func matrixReshape(mat [][]int, r int, c int) [][]int {
    m := len(mat)
    n := len(mat[0])

    if m * n != r * c {
        return mat
    }

    ans := make([][]int, r)

    for i := 0; i < r; i++ {
        ans[i] = make([]int, c)
    }

    for i := 0; i < (r * c); i++ {
        x := i % n
        y := i / n
        xx := i % c
        yy := i / c
        ans[yy][xx] = mat[y][x]
    }

    return ans
}
