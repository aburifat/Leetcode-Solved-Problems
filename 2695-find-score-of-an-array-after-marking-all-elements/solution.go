import (
	"container/heap"
)

type HeapData struct {
    value int
    index int
}

type IntHeap []HeapData

func (h IntHeap) Len() int { return len(h) }
func (h IntHeap) Less(i, j int) bool {
    if h[i].value == h[j].value {
        return h[i].index < h[j].index
    }
    return h[i].value < h[j].value
}
func (h IntHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
    *h = append(*h, x.(HeapData))
}

func (h *IntHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n - 1]
    *h = old[:n - 1]
    return x
}

func findScore(nums []int) int64 {
    mark := make([]bool, len(nums), len(nums))
    hp := &IntHeap{}
    heap.Init(hp)
    for i := 0; i < len(nums); i++ {
        heap.Push(hp, HeapData {
         value: nums[i],
         index: i,
        })
    }
    var ans int64 = 0
    for hp.Len() > 0 {
        x := heap.Pop(hp).(HeapData)
        if !mark[x.index] {
            ans += int64(x.value)
            mark[x.index] = true
            if x.index - 1 >= 0 {
                mark[x.index - 1] = true
            }
            if x.index + 1 < len(nums) {
                mark[x.index + 1] = true
            }
        }
    }
    return ans
}
