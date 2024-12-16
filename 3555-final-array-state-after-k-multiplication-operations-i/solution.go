type Data struct {
    index int
    value int
}

type IntHeap []Data

func (hp IntHeap) Len() int { return len(hp) }

func (hp IntHeap) Less(i, j int) bool {
    if hp[i].value == hp[j].value {
        return hp[i].index < hp[j].index
    }
    return hp[i].value < hp[j].value
}

func (hp IntHeap) Swap(i, j int) { hp[i], hp[j] = hp[j], hp[i] }

func (hp *IntHeap) Push(x interface{}) { *hp = append(*hp, x.(Data)) }

func (hp *IntHeap) Pop() interface{} {
    old := *hp
    n := len(old)
    x := old[n-1]
    *hp = old[0:n-1]
    return x
}

func getFinalState(nums []int, k int, multiplier int) []int {
    hp := &IntHeap{}
    heap.Init(hp)
    for idx, val := range nums {
        heap.Push(hp, Data {
            index: idx,
            value: val,
        })
    }
    for ; k > 0; k-- {
        x := heap.Pop(hp).(Data)
        heap.Push(hp, Data {
            index: x.index,
            value: x.value * multiplier,
        })
    }
    for hp.Len() > 0 {
        x := heap.Pop(hp).(Data)
        nums[x.index] = x.value
    }
    return nums
}
