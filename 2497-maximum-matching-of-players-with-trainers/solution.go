import (
    "sort"
    "sync"
)

func matchPlayersAndTrainers(players []int, trainers []int) int {
    var wg sync.WaitGroup
    wg.Add(2)

    go func() {
        defer wg.Done()
        sort.Ints(players)
    }()

    go func() {
        defer wg.Done()
        sort.Ints(trainers)
    }()

    wg.Wait()

    ct := 0
    for i, j := 0, 0; i < len(players) && j < len(trainers); {
        if players[i] > trainers[j] {
            j++
        } else {
            i++
            j++
            ct++
        }
    }

    return ct
}
