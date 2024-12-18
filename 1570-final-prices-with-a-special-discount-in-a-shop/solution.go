type Stack []int

func (st *Stack) Push(x int) { *st = append(*st, x) }

func (st Stack) Peek() int { return st[len(st) - 1] }

func (st *Stack) Pop() int {
    old := *st
    n := len(old)
    x := old[n-1]
    *st = old[:n-1]
    return x
}

func (st Stack) IsEmpty() bool { return len(st) == 0 }

func finalPrices(prices []int) []int {
    ans := make([]int, len(prices))
    st := &Stack{}
    for i := len(prices) - 1; i >= 0; i-- {
        for !st.IsEmpty() && st.Peek() > prices[i] {
            st.Pop()
        }
        ans[i] = prices[i]
        if !st.IsEmpty() {
            ans[i] -= st.Peek()
        }
        st.Push(prices[i])
    }
    return ans
}
