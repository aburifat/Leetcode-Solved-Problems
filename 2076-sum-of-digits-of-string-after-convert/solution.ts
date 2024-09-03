function getLucky(s: string, k: number): number {
    let sum = 0;
    const base = 'a'.charCodeAt(0) - 1;
    for(let i = 0; i < s.length; i++) {
        const charCode = s.charCodeAt(i) - base;
        sum += 0 | (charCode / 10) + (charCode % 10);
    }
    k--;
    while(k--) {
        let nextSum = 0;
        while(sum > 0) {
            nextSum += sum %10;
            sum = 0 | (sum / 10);
        }
        sum = nextSum;
    }
    return sum;
};
