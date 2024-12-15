type Result struct {
    passed float64
    total float64
}

type PQ []Result

func (pq PQ) Len() int { return len(pq) }

func (pq PQ) Less(i, j int) bool {
    fcti := (pq[i].total - pq[i].passed) / (pq[i].total * (pq[i].total + 1))
    fctj := (pq[j].total - pq[j].passed) / (pq[j].total * (pq[j].total + 1))
    return fcti > fctj
}

func (pq PQ) Swap(i, j int) { pq[i], pq[j] = pq[j], pq[i] }

func (pq *PQ) Push(x interface{}) { *pq = append(*pq, x.(Result))}

func (pq *PQ) Pop() interface{} {
    old := *pq
    n := len(old)
    x := old[n-1]
    *pq = old[:n-1]
    return x
}

func maxAverageRatio(classes [][]int, extraStudents int) float64 {
    pq := &PQ{}
    heap.Init(pq)
    for _, class := range classes {
        heap.Push(pq, Result {
            passed: float64(class[0]),
            total: float64(class[1]),
        })
    }

    for extraStudents > 0 {
        extraStudents--
        class := heap.Pop(pq).(Result)
        class.passed++
        class.total++
        heap.Push(pq, class)
    }

    ans := float64(0)
    for pq.Len() > 0 {
        class := heap.Pop(pq).(Result)
        ans += (class.passed / class.total)
    }
    ans /= float64(len(classes))

    return ans
}
