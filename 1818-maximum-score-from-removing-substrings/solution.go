func remove(word *[]byte, first, second byte, gain int) int {
    point := 0
    stack := []byte{}

    for _, ch := range *word {
        if ch == second && len(stack) > 0 &&
            stack[len(stack) - 1] == first {
            stack = stack[0 : len(stack) - 1]
            point += gain
        } else {
            stack = append(stack, ch)
        }
    }

    *word = stack

    return point
}

func maximumGain(s string, x int, y int) int {
    word := []byte(s)
    pre, post := byte('a'), byte('b')

    if x < y {
        x, y = y, x
        pre, post = post, pre
    }

    return remove(&word, pre, post, x) + remove(&word, post, pre, y)
}
