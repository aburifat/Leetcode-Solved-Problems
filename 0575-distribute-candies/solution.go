func distributeCandies(candyType []int) int {
    limit := len(candyType) / 2
    unique := make(map[int]bool, limit)
    for _, val := range candyType {
        unique[val] = true
        if len(unique) == limit {
            return limit
        }
    }

    return len(unique)
}
