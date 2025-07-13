function createCounter(n: number): () => number {
    var counter: number = n
    return function() {
        return counter++
    }
}


/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
