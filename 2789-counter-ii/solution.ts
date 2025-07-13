type Counter = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(init: number): Counter {
    var initial: number = init
    var count: number = init

    return {
        increment() {
            return ++count;
        },
        decrement() {
            return --count;
        },
        reset() {
            return count = initial
        }
    } satisfies Counter;
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
